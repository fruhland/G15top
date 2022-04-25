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

#include <cstdint>
#include <csignal>
#include <iostream>
#include <unistd.h>
#include "draw/Screen.h"
#include "draw/memory/MemoryBar.h"
#include "draw/memory/MemoryPercentage.h"

bool isRunning = true;

void signalHandler(int32_t signal) {
    isRunning = false;
}

int32_t main(int32_t argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./g15top <path to theme>" << std::endl;
        return -1;
    }

    G15::Draw::Screen screen(argv[1]);
    G15::Draw::MemoryBar memoryBar(screen, 118, 13, 156, 15);
    G15::Draw::MemoryPercentage memoryPercentage(screen, 98, 11, G15::Draw::Screen::FontSize::MEDIUM);

    signal(SIGINT, signalHandler);
    while (isRunning) {
        memoryBar.draw();
        memoryPercentage.draw();
        screen.flush();
        sleep(1);
    }
}