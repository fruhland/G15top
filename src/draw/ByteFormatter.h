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

#ifndef G15TOP_BITFORMATTER_H
#define G15TOP_BITFORMATTER_H

#include "ValueFormatter.h"

namespace G15::Draw {

class ByteFormatter : public ValueFormatter {

public:
    /**
     * Constructor.
     */
    explicit ByteFormatter(const Monitor::Monitorable &monitorable, uint32_t padding);

    /**
     * Copy constructor.
     */
    ByteFormatter(const Formatter &other) = delete;

    /**
     * Assignment operator.
     */
    ByteFormatter &operator=(const ByteFormatter &other) = delete;

    /**
     * Destructor.
     */
    ~ByteFormatter() override = default;

    [[nodiscard]] std::string getText() const override;

private:

    static std::string formatHighValue(uint64_t value);

    static std::string formatLowValue(uint64_t value);

private:

    static const char *highMetricTable[];

    static const char *lowMetricTable[];

    static const constexpr uint32_t tableSize = 7;
};

}

#endif
