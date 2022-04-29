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

#ifndef G15TOP_VALUEFORMATTER_H
#define G15TOP_VALUEFORMATTER_H

#include "Formatter.h"

namespace G15::Draw {

class ValueFormatter : public Formatter {

public:
    /**
     * Constructor.
     */
    explicit ValueFormatter(const Monitor::Monitorable &monitorable, uint32_t padding);

    /**
     * Copy constructor.
     */
    ValueFormatter(const Formatter &other) = delete;

    /**
     * Assignment operator.
     */
    ValueFormatter &operator=(const ValueFormatter &other) = delete;

    /**
     * Destructor.
     */
    ~ValueFormatter() override = default;

    [[nodiscard]] std::string getText() const override;

private:

    uint32_t padding;
};

}

#endif
