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

#ifndef G15TOP_MEMORYDRAWABLE_H
#define G15TOP_MEMORYDRAWABLE_H

#include <glibtop/mem.h>
#include "../Screen.h"
#include "../Drawable.h"

namespace G15::Draw {

class MemoryDrawable : public Drawable {

public:
    /**
     * Constructor.
     */
    explicit MemoryDrawable(Screen &screen);

    /**
     * Copy constructor.
     */
    MemoryDrawable(const MemoryDrawable &other) = delete;

    /**
     * Assignment operator.
     */
    MemoryDrawable &operator=(const MemoryDrawable &other) = delete;

    /**
     * Destructor.
     */
    ~MemoryDrawable() = default;

    void draw() override = 0;

protected:

    void refresh();

    [[nodiscard]] uint64_t getTotalMemory() const;

    [[nodiscard]] uint64_t getUsedMemory() const;

private:

    glibtop_mem memoryInfo{};
};

}

#endif