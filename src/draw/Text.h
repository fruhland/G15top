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

#ifndef G15TOP_TEXT_H
#define G15TOP_TEXT_H

#include "../monitor/TextMonitorable.h"
#include "Screen.h"
#include "Drawable.h"

namespace G15::Draw {

class Text : public Drawable {

public:
    /**
     * Constructor.
     */
    Text(Screen &screen, Monitor::TextMonitorable &monitorable, uint8_t x, uint8_t y, Screen::FontSize size);

    /**
     * Copy constructor.
     */
    Text(const Text &other) = delete;

    /**
     * Assignment operator.
     */
    Text &operator=(const Text &other) = delete;

    /**
     * Destructor.
     */
    ~Text() override = default;

    void draw() override;

protected:

    Screen::FontSize size;
    Monitor::TextMonitorable &monitorable;
};

}

#endif
