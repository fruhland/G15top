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

#ifndef G15TOP_MEMORYBAR_H
#define G15TOP_MEMORYBAR_H

#include "MemoryDrawable.h"

namespace G15::Draw {

class MemoryBar : public MemoryDrawable {

public:
    /**
     * Constructor.
     */
    MemoryBar(Screen &screen, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);

    /**
     * Copy constructor.
     */
    MemoryBar(const MemoryBar &other) = delete;

    /**
     * Assignment operator.
     */
    MemoryBar &operator=(const MemoryBar &other) = delete;

    /**
     * Destructor.
     */
    ~MemoryBar() = default;

    void draw() override;

private:

    uint32_t x1, y1, x2, y2;
};

}

#endif