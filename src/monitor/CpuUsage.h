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

#ifndef G15TOP_CPUUSAGE_H
#define G15TOP_CPUUSAGE_H

#include <glibtop/cpu.h>
#include "PercentageMonitorable.h"

namespace G15::Monitor {

class CpuUsage : public PercentageMonitorable {

public:
    /**
     * Constructor for monitoring total cpuUsage usage.
     */
    CpuUsage();

    /**
     * Constructor for monitoring a specific cpuUsage core.
     */
    explicit CpuUsage(uint64_t core);

    /**
     * Copy constructor.
     */
    CpuUsage(const CpuUsage &other) = delete;

    /**
     * Move constructor.
     */
    CpuUsage(CpuUsage &&other) noexcept;

    /**
     * Assignment operator.
     */
    CpuUsage &operator=(const CpuUsage &other) = delete;

    /**
     * Destructor.
     */
    ~CpuUsage() = default;

    void refresh() override;

    [[nodiscard]] uint64_t getTotal() const override;

    [[nodiscard]] uint64_t getValue() const override;

private:

    uint64_t core;
    glibtop_cpu lastCpuInfo{};
    glibtop_cpu currentCpuInfo{};
};

}

#endif
