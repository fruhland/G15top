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
        clock("%X"), cpuFrequency(CpuFrequency::AVERAGE) {
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
    cpuUsage.refresh();
    cpuFrequency.refresh();
    for (uint64_t i = 0; i < cpuCoreCount; i++) {
        cpuCoreUsage[i].refresh();
        cpuCoreFrequency[i].refresh();
    }
}

Clock& Monitor::getClock() const {
    return const_cast<Clock&>(clock);
}

Memory& Monitor::getMemory() const {
    return const_cast<Memory&>(memory);
}

Swap& Monitor::getSwap() const {
    return const_cast<Swap&>(swap);
}

CpuUsage& Monitor::getCpuUsage() const {
    return const_cast<CpuUsage&>(cpuUsage);
}

CpuUsage &Monitor::getCpuCoreUsage(uint64_t core) const {
    return const_cast<CpuUsage&>(cpuCoreUsage[core]);
}

CpuFrequency& Monitor::getCpuFrequency() const {
    return const_cast<CpuFrequency&>(cpuFrequency);
}

CpuFrequency& Monitor::getCpuCoreFrequency(uint64_t core) const {
    return const_cast<CpuFrequency&>(cpuCoreFrequency[core]);
}

uint64_t Monitor::getCpuCoreCount() const {
    return cpuCoreUsage.size();
}

}