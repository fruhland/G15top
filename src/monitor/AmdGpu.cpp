/*
 * Copyright (C) 2022 Fabian Ruhland <ruhland@hhu.de>
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <dirent.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include "AmdGpu.h"
#include "../util/Exception.h"

namespace G15::Monitor {

AmdGpu::AmdGpu(const char *pciId) {
    metricsFileStream = std::ifstream(std::string(AMDGPU_PATH) + "/" + pciId + "/" + "gpu_metrics", std::ios_base::in | std::ios_base::binary);
    if (!metricsFileStream.is_open()) {
        throw Util::Exception("AmdGpu: Failed to open file '" + std::string(AMDGPU_PATH) + "/" + pciId + "/" + "gpu_metrics" + "'!");
    }

    metricsFileStream.read(reinterpret_cast<char *>(&metricsHeader), sizeof(GpuMetricsHeader));

    /* Based on https://github.com/flightlessmango/MangoHud/blob/master/src/amdgpu.cpp */
    bool supported = false;
    switch (metricsHeader.formatRevision) {
        case 1: // v1.1, v1.2, v1.3
            if (metricsHeader.contentRevision <= 0 ||
                metricsHeader.contentRevision > 3) { // v1.0, not naturally aligned
                break;
            }

            supported = true;
            break;
        case 2: // v2.1, v2.2, v2.3, v2.4
            if (metricsHeader.contentRevision <= 0 ||
                metricsHeader.contentRevision > 4) { // v2.0, not naturally aligned
                break;
            }

            supported = true;
            break;
        default:
            break;
    }

    if (!supported) {
        throw Util::Exception("AmdGpu: Unsupported metrics version: '" + std::to_string(metricsHeader.formatRevision) + "/" +std::to_string(metricsHeader.contentRevision) + "'!");
    }
}

std::vector<std::string> AmdGpu::searchPciIds() {
    auto gpus = std::vector<std::string>();

    auto *amdDirectory = opendir(AMDGPU_PATH);
    if (amdDirectory == nullptr) {
        return gpus;
    }

    dirent *entry;
    while ((entry = readdir(amdDirectory)) != nullptr) {
        if ((entry->d_type == DT_DIR || entry->d_type == DT_LNK) && strlen(entry->d_name) == 12) {
            gpus.emplace_back(entry->d_name);
        }
    }

    return gpus;
}

void AmdGpu::refresh() {
    auto *buffer = new char[metricsHeader.structureSize]{};

    metricsFileStream.seekg(0, std::ios_base::beg);
    metricsFileStream.read(buffer, metricsHeader.structureSize);

    switch (metricsHeader.formatRevision) {
        case 1: {
            auto *metrics = reinterpret_cast<const GpuMetrics13 *>(buffer);
            graphicsUsage = metrics->averageGfxActivity;
            mediaUsage = metrics->averageVideoActivity;
            coreTemperature = metrics->temperatureEdge;
            break;
        }
        case 2: {
            auto *metrics = reinterpret_cast<const GpuMetrics24 *>(buffer);
            graphicsUsage = metrics->averageGfxActivity;
            mediaUsage = metrics->averageVideoActivity;
            coreTemperature = metrics->temperatureGfx;
            break;
        }
        default:
            break;
    }
}

uint64_t AmdGpu::getValue() const {
    throw Util::Exception("AmdGpu: Calling getValue() on the GPU struct directly is not supported!");
}

uint16_t AmdGpu::getGraphicsUsage() const {
    return graphicsUsage;
}

uint16_t AmdGpu::getMediaUsage() const {
    return mediaUsage;
}

uint16_t AmdGpu::getCoreTemperature() const {
    return coreTemperature;
}

}