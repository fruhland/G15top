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

#ifndef G15TOP_MONITOR_H
#define G15TOP_MONITOR_H

#include <vector>
#include <glibtop/mem.h>
#include "Memory.h"
#include "Swap.h"
#include "Clock.h"
#include "CpuUsage.h"
#include "CpuFrequency.h"
#include "NetworkDownload.h"
#include "NetworkUpload.h"
#include "AmdGpu.h"
#include "AmdGpuCoreUsage.h"
#include "AmdGpuMediaUsage.h"
#include "AmdGpuCoreTemperature.h"
#include "AmdGpuMemoryUsage.h"

namespace G15::Monitor {

class Monitor {

public:
    /**
     * Constructor.
     */
    Monitor();

    /**
     * Copy constructor.
     */
    Monitor(const Monitor &other) = delete;

    /**
     * Assignment operator.
     */
    Monitor &operator=(const Monitor &other) = delete;

    /**
     * Destructor.
     */
    ~Monitor();

    void refresh();

    [[nodiscard]] const Clock &getClock() const;

    [[nodiscard]] const Memory& getMemory() const;

    [[nodiscard]] const Swap& getSwap() const;

    [[nodiscard]] const NetworkDownload& getDownload() const;

    [[nodiscard]] const NetworkUpload& getUpload() const;

    [[nodiscard]] const CpuUsage& getCpuUsage() const;

    [[nodiscard]] const CpuUsage& getCpuCoreUsage(uint64_t core) const;

    [[nodiscard]] const CpuFrequency& getCpuFrequency() const;

    [[nodiscard]] const CpuFrequency& getCpuCoreFrequency(uint64_t core) const;

    [[nodiscard]] uint64_t getCpuCoreCount() const;

    [[nodiscard]] const AmdGpuCoreUsage& getAmdGpuCoreUsage() const;

    [[nodiscard]] const AmdGpuMediaUsage& getAmdGpuMediaUsage() const;

    [[nodiscard]] const AmdGpuCoreTemperature& getAmdGpuCoreTemperature() const;

    [[nodiscard]] const AmdGpuMemoryUsage& getAmdGpuMemoryUsage() const;

private:

    uint64_t cpuCoreCount;
    Clock clock;
    Memory memory;
    Swap swap;
    NetworkDownload download;
    NetworkUpload upload;
    CpuUsage cpuUsage;
    CpuFrequency cpuFrequency;
    std::vector<CpuUsage> cpuCoreUsage;
    std::vector<CpuFrequency> cpuCoreFrequency;
    AmdGpu amdGpu;
    AmdGpuCoreUsage amdGpuCoreUsage;
    AmdGpuMediaUsage amdGpuMediaUsage;
    AmdGpuCoreTemperature amdGpuCoreTemperature;
    AmdGpuMemoryUsage amdGpuMemoryUsage;
};

}

#endif
