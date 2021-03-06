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

#include "Text.h"

namespace G15::Draw {

Text::Text(Screen &screen, std::unique_ptr<Formatter> formatter, uint8_t x, uint8_t y, Screen::FontSize size) :
        Drawable(screen, x, y),
        size(size),
        formatter(std::move(formatter)) {}

void Text::draw() {
    screen.drawString(x, y, formatter->getText().c_str(), size);
}

}