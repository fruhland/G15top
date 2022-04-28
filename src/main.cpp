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
#include "monitor/Monitor.h"
#include "draw/Screen.h"
#include "draw/Text.h"
#include "draw/Bar.h"

bool isRunning = true;

void signalHandler(int32_t signal) {
    isRunning = false;
}

int32_t main(int32_t argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./g15top <path to theme>" << std::endl;
        return -1;
    }

    G15::Monitor::Monitor monitor;
    G15::Draw::Screen screen(argv[1]);

    std::vector<G15::Draw::Bar> cpuBars;
    cpuBars.emplace_back(screen, monitor.getCpuCore(0), 3, 12, 2, 48, G15::Draw::Screen::HORIZONTAL);
    cpuBars.emplace_back(screen, monitor.getCpuCore(1), 3, 13, 2, 48, G15::Draw::Screen::HORIZONTAL);
    cpuBars.emplace_back(screen, monitor.getCpuCore(2), 3, 20, 2, 48, G15::Draw::Screen::HORIZONTAL);
    cpuBars.emplace_back(screen, monitor.getCpuCore(3), 3, 21, 2, 48, G15::Draw::Screen::HORIZONTAL);
    cpuBars.emplace_back(screen, monitor.getCpuCore(4), 3, 28, 2, 48, G15::Draw::Screen::HORIZONTAL);
    cpuBars.emplace_back(screen, monitor.getCpuCore(5), 3, 29, 2, 48, G15::Draw::Screen::HORIZONTAL);
    cpuBars.emplace_back(screen, monitor.getCpuCore(6), 3, 36, 2, 48, G15::Draw::Screen::HORIZONTAL);
    cpuBars.emplace_back(screen, monitor.getCpuCore(7), 3, 37, 2, 48, G15::Draw::Screen::HORIZONTAL);

    G15::Draw::Text clock(screen, monitor.getClock(), 118, 2, G15::Draw::Screen::MEDIUM);

    G15::Draw::Bar memoryBar(screen, monitor.getMemory(), 118, 13, 2, 39, G15::Draw::Screen::HORIZONTAL);
    G15::Draw::Bar swapBar(screen, monitor.getSwap(), 118, 14, 2, 39, G15::Draw::Screen::HORIZONTAL);
    G15::Draw::Text memoryPercentage(screen, monitor.getMemory(), 98, 11, G15::Draw::Screen::MEDIUM);

    screen.clear();
    screen.drawBanner();
    screen.flush();
    sleep(5);

    screen.initializeTheme();
    screen.flush();

    signal(SIGINT, signalHandler);
    while (isRunning) {
        monitor.refresh();
        screen.initializeTheme();

        memoryBar.draw();
        swapBar.draw();
        memoryPercentage.draw();
        clock.draw();

        for (auto &bar : cpuBars) {
            bar.draw();
        }

        screen.flush();
        sleep(1);
    }
}
