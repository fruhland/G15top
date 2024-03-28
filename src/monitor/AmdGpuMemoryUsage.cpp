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

#include <iostream>
#include <sstream>
#include "AmdGpuMemoryUsage.h"
#include "AmdGpu.h"
#include "../util/Exception.h"

namespace G15::Monitor {

AmdGpuMemoryUsage::AmdGpuMemoryUsage(const char *pciId) {
    auto totalMemoryFile = std::ifstream(std::string(AmdGpu::AMDGPU_PATH) + "/" + pciId + "/" + "mem_info_vram_total", std::ios_base::in | std::ios_base::binary);
    if (!totalMemoryFile.is_open()) {
        throw Util::Exception("AmdGpu: Failed to open file '" + std::string(AmdGpu::AMDGPU_PATH) + "/" + pciId + "/" + "mem_info_vram_total" + "'!");
    }

    usedMemoryFile = std::ifstream(std::string(AmdGpu::AMDGPU_PATH) + "/" + pciId + "/" + "mem_info_vram_used", std::ios_base::in | std::ios_base::binary);
    if (!usedMemoryFile.is_open()) {
        throw Util::Exception("AmdGpu: Failed to open file '" + std::string(AmdGpu::AMDGPU_PATH) + "/" + pciId + "/" + "mem_info_vram_total" + "'!");
    }

    std::ostringstream totalMemoryStringStream;
    totalMemoryStringStream << totalMemoryFile.rdbuf();
    totalMemory = atoll(totalMemoryStringStream.str().c_str());
}

void AmdGpuMemoryUsage::refresh() {
    usedMemoryFile.seekg(0);

    std::ostringstream usedMemoryStringStream;
    usedMemoryStringStream << usedMemoryFile.rdbuf();
    usedMemory = atoll(usedMemoryStringStream.str().c_str());
}

uint64_t AmdGpuMemoryUsage::getValue() const {
    return usedMemory;
}

uint64_t AmdGpuMemoryUsage::getTotal() const {
    return totalMemory;
}

}