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

#ifndef G15TOP_CLOCK_H
#define G15TOP_CLOCK_H

#include "../Text.h"

namespace G15::Draw {

class Clock : public Text {

public:
    /**
     * Constructor.
     */
    explicit Clock(Screen &screen, uint32_t x, uint32_t y, Screen::FontSize size, const char *format);

    /**
     * Copy constructor.
     */
    Clock(const Clock &other) = delete;

    /**
     * Assignment operator.
     */
    Clock &operator=(const Clock &other) = delete;

    /**
     * Destructor.
     */
    ~Clock() = default;

    void draw() override;

private:

    std::string format;
};

}

#endif
