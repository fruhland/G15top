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

#ifndef G15TOP_STATISTICS_H
#define G15TOP_STATISTICS_H

#include <cstdint>
#include <glibtop/mem.h>

namespace G15::Util {

class Statistics {

public:

    /**
     * Constructor.
     */
    explicit Statistics() = default;

    /**
     * Copy constructor.
     */
    Statistics(const Statistics &other) = delete;

    /**
     * Assignment operator.
     */
    Statistics &operator=(const Statistics &other) = delete;

    /**
     * Destructor.
     */
    ~Statistics() = default;

    void refresh();

    [[nodiscard]] uint64_t getTotalMemory() const;

    [[nodiscard]] uint64_t getUsedMemory() const;

private:

    glibtop_mem memoryInfo{};
};

}

#endif
