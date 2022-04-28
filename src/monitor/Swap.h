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

#ifndef G15TOP_SWAP_H
#define G15TOP_SWAP_H

#include <cstdint>
#include <glibtop/swap.h>
#include "MemoryMonitorable.h"

namespace G15::Monitor {

class Swap : public MemoryMonitorable {

public:
    /**
     * Constructor.
     */
    explicit Swap() = default;

    /**
     * Copy constructor.
     */
    Swap(const Swap &other) = delete;

    /**
     * Assignment operator.
     */
    Swap &operator=(const Swap &other) = delete;

    /**
     * Destructor.
     */
    ~Swap() = default;

    void refresh() override;

    [[nodiscard]] uint64_t getTotal() const override;

    [[nodiscard]] uint64_t getUsed() const override;

private:

    glibtop_swap swapInfo{};
};

}

#endif
