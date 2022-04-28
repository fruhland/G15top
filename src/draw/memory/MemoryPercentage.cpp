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

#include "MemoryPercentage.h"

namespace G15::Draw {

MemoryPercentage::MemoryPercentage(Screen &screen, Monitor::MemoryMonitorable &memory, uint32_t x, uint32_t y, Screen::FontSize size) :
        Text(screen, x, y, size),
        memory(memory) {}

void MemoryPercentage::draw() {
    auto usedMemory = memory.getUsed();
    auto totalMemory = memory.getTotal();
    auto percentage = static_cast<double>(usedMemory) / static_cast<double>(totalMemory) * 100;

    screen.drawNumber(x, y, static_cast<uint32_t>(percentage >= 100 ? 99 : percentage), size);
}

}