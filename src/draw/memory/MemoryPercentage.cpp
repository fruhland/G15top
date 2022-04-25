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

MemoryPercentage::MemoryPercentage(Screen &screen, uint32_t x, uint32_t y, Screen::FontSize size) :
        MemoryDrawable(screen),
        x(x), y(y), fontSize(fontSize) {}

void MemoryPercentage::draw() {
    refresh();
    auto percentage = static_cast<double>(getUsedMemory()) / static_cast<double>(getTotalMemory()) * 100;
    getScreen().drawNumber(x, y, static_cast<uint32_t>(percentage), fontSize);
}

}