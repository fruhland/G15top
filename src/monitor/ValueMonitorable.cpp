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

#include "ValueMonitorable.h"

namespace G15::Monitor {

double Monitor::ValueMonitorable::getPercentage() const {
    return static_cast<double>(getValue()) / static_cast<double>(getTotal());
}

std::string ValueMonitorable::getText() const {
    auto percentage = static_cast<uint8_t>(getPercentage() * 100);
    return std::to_string(percentage >= 100 ? 99 : percentage);
}

}