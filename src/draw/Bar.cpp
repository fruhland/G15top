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

#include "Bar.h"

namespace G15::Draw {

Bar::Bar(Screen &screen, Monitor::PercentageMonitorable &monitorable, uint8_t x, uint8_t y, uint8_t width, uint8_t length, Screen::Orientation orientation) :
        Drawable(screen, x, y),
        width(width), length(length),
        orientation(orientation),
        monitorable(monitorable) {}

void Bar::draw() {
    if (orientation == Screen::HORIZONTAL) {
        screen.drawHorizontalProgressBar(x, y, x + (length - 1), y + (width - 1), monitorable.getPercentage());
    } else {
        screen.drawVerticalProgressBar(x, y - (length - 1), x + (width - 1), y, monitorable.getPercentage());
    }
}

Bar::Bar(const Bar &&other) noexcept :
        Drawable(other.screen, other.x, other.y),
        width(other.width), length(other.length),
        orientation(other.orientation),
        monitorable(other.monitorable) {}

}