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

#include <string>
#include "ValueFormatter.h"

namespace G15::Draw {

ValueFormatter::ValueFormatter(const Monitor::Monitorable &monitorable, uint32_t padding) :
        Formatter(monitorable),
        padding(padding) {}

std::string ValueFormatter::getText() const {
    auto valueString = std::to_string(static_cast<uint32_t>(monitorable.getValue()));
    auto spaceString = std::string("");

    if (padding > valueString.size()) {
        for (int32_t i = 0; i < padding - valueString.length(); i++) {
            spaceString += " ";
        }
    }

    return spaceString + valueString;
}

}