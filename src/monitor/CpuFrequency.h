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

#ifndef G15TOP_CPUFREQUENCY_H
#define G15TOP_CPUFREQUENCY_H

#include "Monitorable.h"

namespace G15::Monitor {

class CpuFrequency : public Monitorable {

public:

    enum GatheringMode {
        MIN,
        MAX,
        AVERAGE
    };

    /**
     * Constructor for monitoring total cpu frequency.
     */
    explicit CpuFrequency(GatheringMode mode);

    /**
     * Constructor for monitoring a specific cpuUsage core.
     */
    explicit CpuFrequency(uint64_t core);

    /**
     * Copy constructor.
     */
    CpuFrequency(const CpuFrequency &other) = delete;

    /**
     * Move constructor.
     */
    CpuFrequency(CpuFrequency &&other) noexcept;

    /**
     * Assignment operator.
     */
    CpuFrequency &operator=(const CpuFrequency &other) = delete;

    /**
     * Destructor.
     */
    ~CpuFrequency() = default;

    void refresh() override;

    [[nodiscard]] uint64_t getValue() const override;

private:

    [[nodiscard]] static double readFrequency(uint64_t core);

    [[nodiscard]] static double calculateMinFrequency();

    [[nodiscard]] static double calculateMaxFrequency();

    [[nodiscard]] static double calculateAverageFrequency();

    uint64_t core;
    GatheringMode gatheringMode;
    double currentFrequency{};

    static const constexpr char *FREQUENCY_KEY = "cpu MHz";
};

}

#endif
