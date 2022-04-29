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

#include <csignal>
#include <iostream>
#include <unistd.h>
#include "monitor/Monitor.h"
#include "draw/Screen.h"
#include "draw/Text.h"
#include "draw/Bar.h"
#include "draw/DateTimeFormatter.h"
#include "draw/PercentageFormatter.h"
#include "draw/ValueFormatter.h"

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

    auto clock = std::make_unique<G15::Draw::DateTimeFormatter>(monitor.getClock(), "%X");
    auto memoryPercentage = std::make_unique<G15::Draw::PercentageFormatter>(monitor.getMemory());
    auto cpuFrequency = std::make_unique<G15::Draw::ValueFormatter>(monitor.getCpuFrequency(), 4);

    screen.registerDrawable(std::make_unique<G15::Draw::Text>(screen, std::move(clock), 118, 2, G15::Draw::Screen::MEDIUM));

    screen.registerDrawable(std::make_unique<G15::Draw::Bar>(screen, monitor.getMemory(), 118, 13, 2, 39, G15::Draw::Screen::HORIZONTAL));
    screen.registerDrawable(std::make_unique<G15::Draw::Bar>(screen, monitor.getSwap(), 118, 14, 2, 39, G15::Draw::Screen::HORIZONTAL));
    screen.registerDrawable(std::make_unique<G15::Draw::Text>(screen, std::move(memoryPercentage), 98, 11, G15::Draw::Screen::MEDIUM));

    screen.registerDrawable(std::make_unique<G15::Draw::Text>(screen, std::move(cpuFrequency), 25, 2, G15::Draw::Screen::MEDIUM));

    uint8_t cpuOffset = 0;
    for (uint64_t i = 0; i < monitor.getCpuCoreCount(); i++) {
        screen.registerDrawable(std::make_unique<G15::Draw::Bar>(screen, monitor.getCpuCoreUsage(i), 3, 12 + cpuOffset, 2, 45, G15::Draw::Screen::HORIZONTAL));
        cpuOffset += i % 2 == 0 ? 1 : 7;
    }

    screen.clear();
    screen.drawBanner();
    sleep(5);

    screen.drawTheme();
    screen.draw();

    signal(SIGINT, signalHandler);
    while (isRunning) {
        monitor.refresh();
        screen.draw();

        sleep(1);
    }
}
