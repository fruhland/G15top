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

#include <unistd.h>
#include <g15daemon_client.h>
#include <fstream>
#include "../util/BuildConfig.h"
#include "../util/Exception.h"
#include "Screen.h"

namespace G15::Draw {

Screen::Screen(const char *theme) : Drawable(*this, 0, 0), theme(std::string(theme) + "/theme.wbmp") {
    screen = new_g15_screen(G15_G15RBUF);
    if (screen < 0) {
        throw Util::Exception("Unable to initialize G15 screen!");
    }

    g15r_initCanvas(&canvas);
}

Screen::~Screen() {
    close(screen);
}

void Screen::clear() {
    g15r_clearScreen(&canvas, G15_COLOR_WHITE);
}

void Screen::drawBanner() {
    drawString(4, 4, "  ____________ __           ", G15::Draw::Screen::SMALL);
    drawString(4, 10, (" / ___<  / __// /____  ___  " + std::string(G15::Util::BuildConfig::getVersion())).c_str(), G15::Draw::Screen::SMALL);
    drawString(4, 16, (R"(/ (_ // /__ \/ __/ _ \/ _ \ )" + std::string(G15::Util::BuildConfig::getBuildDate()).substr(0, 10)).c_str(), G15::Draw::Screen::SMALL);
    drawString(4, 22, (R"(\___//_/____/\__/\___/ .__/ )" + std::string(G15::Util::BuildConfig::getGitBranch())).c_str(), G15::Draw::Screen::SMALL);
    drawString(4, 28, ("                    /_/     " + std::string(G15::Util::BuildConfig::getGitRevision())).c_str(), G15::Draw::Screen::SMALL);

    g15_send(screen, reinterpret_cast<char *>(canvas.buffer), G15_BUFFER_LEN);
}

void Screen::drawTheme() {
    if (!checkFile(theme.c_str())) {
        throw Util::Exception("Theme not found '" + theme + "'!");
    }

    drawSplash(theme.c_str());
}

void Screen::drawHorizontalProgressBar(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, double percentage) {
    auto length = (x2 - x1) * percentage;
    if (length < 1) {
        return;
    }

    g15r_pixelReverseFill(&canvas, static_cast<int32_t>(x1), static_cast<int32_t>(y1),
                          static_cast<int32_t>(x1 + length), static_cast<int32_t>(y2), G15_PIXEL_FILL, G15_COLOR_BLACK);
}

void Screen::drawVerticalProgressBar(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, double percentage) {
    auto height = (y2 - y1) * percentage;
    if (height < 1) {
        return;
    }

    g15r_pixelReverseFill(&canvas, static_cast<int32_t>(x1), static_cast<int32_t>(y2 - height),
                          static_cast<int32_t>(x2), static_cast<int32_t>(y2), G15_PIXEL_FILL, G15_COLOR_BLACK);
}

void Screen::drawString(uint32_t x, uint32_t y, const char *string, FontSize size) {
    g15r_renderString(&canvas, (unsigned char*) string, 0, size, x, y);
}

void Screen::draw() {
    drawTheme();

    for (auto &drawable : drawables) {
        drawable->draw();
    }

    g15_send(screen, reinterpret_cast<char *>(canvas.buffer), G15_BUFFER_LEN);
}

void Screen::drawSplash(const char *path) {
    g15r_loadWbmpSplash(&canvas, (char *) path);
}

bool Screen::checkFile(const char *path) {
    std::ifstream file(path);
    return file.is_open();
}

void Screen::registerDrawable(std::unique_ptr<Drawable> drawable) {
    drawables.push_back(std::move(drawable));
}

}