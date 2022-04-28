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

#ifndef G15TOP_TEXTMONITORABLE_H
#define G15TOP_TEXTMONITORABLE_H

#include <cstdint>
#include <string>
#include "Monitorable.h"

namespace G15::Monitor {

class TextMonitorable : public Monitorable {

public:
    /**
     * Constructor.
     */
    TextMonitorable() = default;

    /**
     * Copy constructor.
     */
    TextMonitorable(const TextMonitorable &other) = delete;

    /**
     * Assignment operator.
     */
    TextMonitorable &operator=(const TextMonitorable &other) = delete;

    /**
     * Destructor.
     */
    ~TextMonitorable() = default;

    void refresh() override = 0;

    [[nodiscard]] virtual std::string getText() const = 0;
};

}

#endif