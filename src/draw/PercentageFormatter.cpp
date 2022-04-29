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

#include "PercentageFormatter.h"

namespace G15::Draw {

PercentageFormatter::PercentageFormatter(const Monitor::PercentageMonitorable &monitorable) :
        Formatter(monitorable) {}

std::string PercentageFormatter::getText() const {
    auto value = reinterpret_cast<const Monitor::PercentageMonitorable&>(monitorable).getPercentage() * 100;
    auto string = std::to_string(static_cast<uint32_t>(value >= 100 ? 99 : value));
    return string.length() < 2 ? " " + string : string;
}

}