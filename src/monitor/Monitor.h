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

    [[nodiscard]] Clock &getClock() const;

    [[nodiscard]] Memory& getMemory() const;

    [[nodiscard]] Swap& getSwap() const;

    [[nodiscard]] NetworkDownload& getDownload() const;

    [[nodiscard]] NetworkUpload& getUpload() const;

    [[nodiscard]] CpuUsage& getCpuUsage() const;

    [[nodiscard]] CpuUsage& getCpuCoreUsage(uint64_t core) const;

    [[nodiscard]] CpuFrequency& getCpuFrequency() const;

    [[nodiscard]] CpuFrequency& getCpuCoreFrequency(uint64_t core) const;

    [[nodiscard]] uint64_t getCpuCoreCount() const;

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
};

}

#endif
