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

#ifndef G15TOP_DRAWABLE_H
#define G15TOP_DRAWABLE_H

namespace G15::Draw {

class Screen;

class Drawable {

public:
    /**
     * Constructor.
     */
    Drawable(Screen &screen, uint8_t x, uint8_t y);

    /**
     * Copy constructor.
     */
    Drawable(const Drawable &other) = delete;

    /**
     * Assignment operator.
     */
    Drawable &operator=(const Drawable &other) = delete;

    /**
     * Destructor.
     */
    virtual ~Drawable() = default;

    virtual void draw() = 0;

protected:

    Screen &screen;
    uint8_t x, y;
};

}

#endif