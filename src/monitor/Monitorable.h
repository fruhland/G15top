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

#ifndef G15TOP_MONITORABLE_H
#define G15TOP_MONITORABLE_H

#include <cstdint>

namespace G15::Monitor {

class Monitorable {

public:
    /**
     * Constructor.
     */
    Monitorable() = default;

    /**
     * Copy constructor.
     */
    Monitorable(const Monitorable &other) = delete;

    /**
     * Assignment operator.
     */
    Monitorable &operator=(const Monitorable &other) = delete;

    /**
     * Destructor.
     */
    virtual ~Monitorable() = default;

    virtual void refresh() = 0;

    [[nodiscard]] virtual uint64_t getValue() const = 0;
};

}

#endif
