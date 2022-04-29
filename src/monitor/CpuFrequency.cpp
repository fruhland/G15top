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

#include <glibtop/sysinfo.h>
#include "CpuFrequency.h"

namespace G15::Monitor {

CpuFrequency::CpuFrequency(CpuFrequency::GatheringMode mode) :
        core(UINT64_MAX),
        gatheringMode(mode) {}

CpuFrequency::CpuFrequency(uint64_t core) :
        core(core),
        gatheringMode(AVERAGE) {}

CpuFrequency::CpuFrequency(CpuFrequency &&other) noexcept :
        core(other.core),
        gatheringMode(other.gatheringMode) {}

void CpuFrequency::refresh() {
    const auto &systemInfo = *glibtop_get_sysinfo();

    if (core == UINT64_MAX) {
        switch (gatheringMode) {
            case MIN:
                currentFrequency = calculateMinFrequency();
                break;
            case MAX:
                currentFrequency = calculateMaxFrequency();
                break;
            case AVERAGE:
                currentFrequency = calculateAverageFrequency();
                break;
        }
    } else {
        currentFrequency = readFrequency(core);
    }
}

double CpuFrequency::readFrequency(uint64_t core) {
    const auto &systemInfo = *glibtop_get_sysinfo();
    auto rawFrequency = static_cast<const char*>(g_hash_table_lookup(systemInfo.cpuinfo[core].values, FREQUENCY_KEY));
    return std::strtod(rawFrequency, nullptr);
}

double CpuFrequency::calculateMinFrequency() {
    const auto &systemInfo = *glibtop_get_sysinfo();

    double minFrequency = readFrequency(0);
    for (uint64_t i = 0; i < systemInfo.ncpu; i++) {
        auto frequency = readFrequency(i);
        minFrequency = frequency < minFrequency ? frequency : minFrequency;
    }

    return minFrequency;
}

double CpuFrequency::calculateMaxFrequency() {
    const auto &systemInfo = *glibtop_get_sysinfo();

    double maxFrequency = readFrequency(0);
    for (uint64_t i = 0; i < systemInfo.ncpu; i++) {
        auto frequency = readFrequency(i);
        maxFrequency = frequency > maxFrequency ? frequency : maxFrequency;
    }

    return maxFrequency;
}

double CpuFrequency::calculateAverageFrequency() {
    const auto &systemInfo = *glibtop_get_sysinfo();

    double frequencySum = 0;
    for (uint64_t i = 0; i < systemInfo.ncpu; i++) {
        frequencySum += readFrequency(i);
    }

    return frequencySum / static_cast<double>(systemInfo.ncpu);
}

uint64_t CpuFrequency::getValue() const {
    return static_cast<uint64_t>(currentFrequency);
}

}