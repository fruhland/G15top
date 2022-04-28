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

#ifndef G15TOP_SCREEN_H
#define G15TOP_SCREEN_H

#include <cstdint>
#include <string>
#include <libg15render.h>

namespace G15::Draw {

class Screen {

public:
    /**
     * Constructor.
     */
    Screen(const char *theme);

    /**
     * Copy constructor.
     */
    Screen(const Screen &other) = delete;

    /**
     * Assignment operator.
     */
    Screen &operator=(const Screen &other) = delete;

    /**
     * Destructor.
     */
    ~Screen();

    enum FontSize {
        SMALL = G15_TEXT_SMALL,
        MEDIUM = G15_TEXT_MED,
        LARGE = G15_TEXT_LARGE
    };

    enum Orientation {
        HORIZONTAL,
        VERTICAL
    };

    void clear();

    void drawBanner();

    void initializeTheme();

    void drawHorizontalProgressBar(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint64_t value, uint64_t maxValue);

    void drawVerticalProgressBar(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint64_t value, uint64_t maxValue);

    void drawString(uint32_t x, uint32_t y, const char *string, FontSize size);

    void drawNumber(uint32_t x, uint32_t y, uint32_t value, FontSize size);

    void flush();

private:

    void drawSplash(const char *path);

    [[nodiscard]] static bool checkFile(const char *path);

    int32_t screen;
    g15canvas canvas{};
    std::string theme;
};

}

#endif