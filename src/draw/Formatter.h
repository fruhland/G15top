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

#ifndef G15TOP_FORMATTER_H
#define G15TOP_FORMATTER_H

#include <string>
#include "../monitor/Monitorable.h"

namespace G15::Draw {

class Formatter {

public:
    /**
     * Constructor.
     */
    explicit Formatter(const Monitor::Monitorable &monitorable);

    /**
     * Copy constructor.
     */
    Formatter(const Formatter &other) = delete;

    /**
     * Assignment operator.
     */
    Formatter &operator=(const Formatter &other) = delete;

    /**
     * Destructor.
     */
    virtual ~Formatter() = default;

    [[nodiscard]] virtual std::string getText() const = 0;

protected:

    const Monitor::Monitorable &monitorable;
};

}

#endif
