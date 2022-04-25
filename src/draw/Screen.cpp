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

#include <stdexcept>
#include <unistd.h>
#include <g15daemon_client.h>
#include <fstream>
#include "../util/Exception.h"
#include "Screen.h"

namespace G15::Draw {

Screen::Screen(const char *theme) {
    auto path = std::string(theme) + "/theme.wbmp";
    if (!checkFile(path.c_str())) {
        throw Util::Exception("Theme not found '" + path + "'!");
    }

    screen = new_g15_screen(G15_G15RBUF);
    if (screen < 0) {
        throw Util::Exception("Unable to initialize G15 screen!");
    }

    g15r_initCanvas(&canvas);
    clear();
    drawSplash((std::string(theme) + "/theme.wbmp").c_str());
    flush();
}

Screen::~Screen() {
    close(screen);
}

void Screen::clear() {
    g15r_clearScreen(&canvas, G15_COLOR_WHITE);
}

void Screen::drawSplash(const char *path) {
    g15r_loadWbmpSplash(&canvas, (char *) path);
}

void Screen::drawProgressBar(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint64_t value, uint64_t maxValue) {
    auto percentage = static_cast<double>(value) / maxValue;
    auto length = (x2 - x1) * percentage;
    g15r_pixelReverseFill(&canvas, x1, y1, static_cast<int32_t>(x1 + length), y2, G15_PIXEL_FILL, G15_COLOR_BLACK);
}

void Screen::drawNumber(uint32_t x, uint32_t y, uint32_t value, Screen::FontSize size) {
    g15r_renderString(&canvas, (unsigned char *) std::to_string(value).c_str(), 0, G15_TEXT_MED, x, y);
}

void Screen::flush() {
    g15_send(screen, reinterpret_cast<char *>(canvas.buffer), G15_BUFFER_LEN);
}

bool Screen::checkFile(const char *path) {
    std::ifstream file(path);
    return file.is_open();
}

}