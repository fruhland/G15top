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

MemoryBar::MemoryBar(Screen &screen, Monitor::Monitor &monitor, uint32_t x, uint32_t y, uint32_t width, uint32_t length, Screen::Orientation orientation) :
        Bar(screen, x, y, width, length, orientation),
        monitor(monitor) {}

void MemoryBar::draw() {
    auto usedMemory = monitor.getMemory().getUsedMemory();
    auto totalMemory = monitor.getMemory().getTotalMemory();

    if (orientation == Screen::HORIZONTAL) {
        screen.drawHorizontalProgressBar(x, y, x + (length - 1), y + (width - 1), usedMemory, totalMemory);
    } else {
        screen.drawVerticalProgressBar(x, y - (length - 1), x + (width - 1), y, usedMemory, totalMemory);
    }
}

}