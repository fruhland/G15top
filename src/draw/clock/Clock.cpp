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

#include "Clock.h"

namespace G15::Draw {

Clock::Clock(Screen &screen, uint32_t x, uint32_t y, Screen::FontSize size, const char *format) :
        Drawable(screen),
        x(x), y(y), size(size), format(format) {}

void Clock::draw() {
    char buffer[128];
    auto rawTime = time(nullptr);
    auto *time = localtime(&rawTime);

    strftime(buffer, sizeof(buffer), format.c_str(), time);
    getScreen().drawString(x, y, buffer, size);
}

}