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

#include <ctime>
#include "DateTimeFormatter.h"

namespace G15::Draw {

DateTimeFormatter::DateTimeFormatter(const Monitor::Monitorable &monitorable, std::string format) :
        Formatter(monitorable),
        timeFormat(std::move(format)){}

std::string DateTimeFormatter::getText() const {
    auto rawTime = static_cast<time_t>(monitorable.getValue());
    auto *time = localtime(&rawTime);
    strftime((char*) buffer, sizeof(buffer), timeFormat.c_str(), time);

    return buffer;
}

}
