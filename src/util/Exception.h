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

#ifndef G15TOP_EXCEPTION_H
#define G15TOP_EXCEPTION_H

#include <stdexcept>

namespace G15::Util {

class Exception : public std::exception {

public:
    /**
     * Constructor.
     */
    explicit Exception(std::string errorMessage);

    /**
     * Copy constructor.
     */
    Exception(const Exception &other) = default;

    /**
     * Assignment operator.
     */
    Exception &operator=(const Exception &other) = default;

    /**
     * Destructor.
     */
    ~Exception() override = default;

    [[nodiscard]] const char *what() const noexcept override;

private:

    std::string errorMessage;
};

}

#endif
