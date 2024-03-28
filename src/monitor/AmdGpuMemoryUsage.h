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

#ifndef G15TOP_AMDGPUMEMORYUSAGE_H
#define G15TOP_AMDGPUMEMORYUSAGE_H

#include <fstream>
#include "PercentageMonitorable.h"

namespace G15::Monitor {

class AmdGpuMemoryUsage : public PercentageMonitorable {

public:
    /**
     * Constructor.
     */
    explicit AmdGpuMemoryUsage(const char *pciId);

    /**
     * Copy constructor.
     */
    AmdGpuMemoryUsage(const AmdGpuMemoryUsage &other) = delete;

    /**
     * Assignment operator.
     */
    AmdGpuMemoryUsage &operator=(const AmdGpuMemoryUsage &other) = delete;

    /**
     * Destructor.
     */
    ~AmdGpuMemoryUsage() override = default;

    void refresh() override;

    [[nodiscard]] uint64_t getValue() const override;

    [[nodiscard]] uint64_t getTotal() const override;

private:

    std::ifstream usedMemoryFile;

    uint64_t usedMemory = 0;
    uint64_t totalMemory = 0;
};

}

#endif
