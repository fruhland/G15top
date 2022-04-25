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

#include "MemoryBar.h"

namespace G15::Draw {

MemoryBar::MemoryBar(Screen &screen, Util::Statistics &statistics, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2) :
        Drawable(screen),
        statistics(statistics),
        x1(x1), y1(y1), x2(x2), y2(y2) {}

void MemoryBar::draw() {
    getScreen().drawProgressBar(x1, y1, x2, y2, statistics.getUsedMemory(), statistics.getTotalMemory());
}

}