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

#include "CpuUsage.h"

namespace G15::Monitor {

CpuUsage::CpuUsage() :
        core(UINT64_MAX) {}

CpuUsage::CpuUsage(uint64_t core) :
        core(core) {}

CpuUsage::CpuUsage(CpuUsage &&other) noexcept :
        core(other.core),
        lastCpuInfo(other.lastCpuInfo),
        currentCpuInfo(other.currentCpuInfo) {}

void CpuUsage::refresh() {
    lastCpuInfo = currentCpuInfo;
    glibtop_get_cpu(&currentCpuInfo);
}

uint64_t CpuUsage::getTotal() const {
    if (core == UINT64_MAX) {
        return currentCpuInfo.total - lastCpuInfo.total;
    }

    return currentCpuInfo.xcpu_total[core] - lastCpuInfo.xcpu_total[core];
}

uint64_t CpuUsage::getValue() const {
    if (core == UINT64_MAX) {
        return (currentCpuInfo.total - currentCpuInfo.idle) - (lastCpuInfo.total - lastCpuInfo.idle);
    }

    return (currentCpuInfo.xcpu_total[core] - currentCpuInfo.xcpu_idle[core]) - (lastCpuInfo.xcpu_total[core] - lastCpuInfo.xcpu_idle[core]);
}

}