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

#ifndef G15TOP_BAR_H
#define G15TOP_BAR_H

#include "Drawable.h"

namespace G15::Draw {

class Bar : public Drawable {

public:
    /**
     * Constructor.
     */
    Bar(Screen &screen, uint32_t x, uint32_t y, uint32_t width, uint32_t length, Screen::Orientation orientation);

    /**
     * Copy constructor.
     */
    Bar(const Bar &other) = delete;

    /**
     * Assignment operator.
     */
    Bar &operator=(const Bar &other) = delete;

    /**
     * Destructor.
     */
    ~Bar() = default;

    void draw() override = 0;

protected:

    uint32_t width, length;
    Screen::Orientation orientation;
};

}

#endif
