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
#include "Monitor.h"

namespace G15::Monitor {

Monitor::Monitor() :
        download("enp5s0u2u1u2"),
        upload("enp5s0u2u1u2"),
        cpuFrequency(CpuFrequency::AVERAGE),
        amdGpu(AmdGpu::searchPciIds()[0].c_str()),
        amdGpuCoreUsage(amdGpu),
        amdGpuMediaUsage(amdGpu),
        amdGpuCoreTemperature(amdGpu),
        amdGpuMemoryUsage(AmdGpu::searchPciIds()[0].c_str()) {
    glibtop_init();

    cpuCoreCount = glibtop_get_sysinfo()->ncpu;
    for (uint64_t i = 0; i < cpuCoreCount; i++) {
        cpuCoreUsage.emplace_back(i);
        cpuCoreFrequency.emplace_back(i);
    }
}

Monitor::~Monitor() {
    glibtop_close();
}

void Monitor::refresh() {
    const_cast<glibtop_sysinfo*>(glibtop_get_sysinfo())->flags = 0;
    clock.refresh();
    memory.refresh();
    swap.refresh();
    download.refresh();
    upload.refresh();
    cpuUsage.refresh();
    cpuFrequency.refresh();
    for (uint64_t i = 0; i < cpuCoreCount; i++) {
        cpuCoreUsage[i].refresh();
        cpuCoreFrequency[i].refresh();
    }
    amdGpu.refresh();
    amdGpuMemoryUsage.refresh();
}

const Clock& Monitor::getClock() const {
    return const_cast<Clock&>(clock);
}

const Memory& Monitor::getMemory() const {
    return const_cast<Memory&>(memory);
}

const Swap& Monitor::getSwap() const {
    return const_cast<Swap&>(swap);
}

const NetworkDownload& Monitor::getDownload() const {
    return const_cast<NetworkDownload&>(download);
}

const NetworkUpload& Monitor::getUpload() const {
    return const_cast<NetworkUpload&>(upload);
}

const CpuUsage& Monitor::getCpuUsage() const {
    return const_cast<CpuUsage&>(cpuUsage);
}

const CpuUsage &Monitor::getCpuCoreUsage(uint64_t core) const {
    return const_cast<CpuUsage&>(cpuCoreUsage[core]);
}

const CpuFrequency& Monitor::getCpuFrequency() const {
    return const_cast<CpuFrequency&>(cpuFrequency);
}

const CpuFrequency& Monitor::getCpuCoreFrequency(uint64_t core) const {
    return const_cast<CpuFrequency&>(cpuCoreFrequency[core]);
}

uint64_t Monitor::getCpuCoreCount() const {
    return cpuCoreUsage.size();
}

const AmdGpuCoreUsage& Monitor::getAmdGpuCoreUsage() const {
    return amdGpuCoreUsage;
}

const AmdGpuMediaUsage& Monitor::getAmdGpuMediaUsage() const {
    return amdGpuMediaUsage;
}

const AmdGpuCoreTemperature& Monitor::getAmdGpuCoreTemperature() const {
    return amdGpuCoreTemperature;
}

const AmdGpuMemoryUsage& Monitor::getAmdGpuMemoryUsage() const {
    return amdGpuMemoryUsage;
}

}
