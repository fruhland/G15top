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

#include "ByteFormatter.h"

namespace G15::Draw {

const char *ByteFormatter::lowMetricTable[] = {
        " ",
        "m",
        "u",
        "n",
        "p",
        "f",
        "a"
};

const char *ByteFormatter::highMetricTable[] = {
        " ",
        "K",
        "M",
        "G",
        "T",
        "P",
        "E"
};

ByteFormatter::ByteFormatter(const Monitor::Monitorable &monitorable, uint32_t padding) :
        ValueFormatter(monitorable, padding) {}

std::string ByteFormatter::getText() const {
    auto value = monitorable.getValue();
    auto byteString = value >= 1 ? formatHighValue(value) : formatLowValue(value);

    auto spaceString = std::string("");
    for (int32_t i = 0; i < padding - byteString.length(); i++) {
        spaceString += " ";
    }

    return spaceString + byteString;
}

std::string ByteFormatter::formatHighValue(uint64_t value) {
    auto formattedValue = static_cast<double>(value);

    uint32_t counter = 0;
    while (formattedValue > 1000 && formattedValue != 0 && counter < tableSize - 1) {
        formattedValue /= 1000;
        counter++;
    }

    return std::to_string(static_cast<uint32_t>(formattedValue)) + " " + highMetricTable[counter] + "B";
}

std::string ByteFormatter::formatLowValue(uint64_t value) {
    auto formattedValue = static_cast<double>(value);

    uint32_t counter = 0;
    while (formattedValue < 1 && formattedValue != 0 && counter < tableSize - 1) {
        formattedValue *= 1000;
        counter++;
    }

    return std::to_string(static_cast<uint32_t>(formattedValue)) + " " + lowMetricTable[counter] + "B";
}

}