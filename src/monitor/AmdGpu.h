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

#ifndef G15TOP_AMDGPU_H
#define G15TOP_AMDGPU_H

#include <cstdint>
#include <string>
#include <vector>
#include <fstream>
#include "Monitorable.h"

namespace G15::Monitor {

class AmdGpu : public Monitorable {

public:
    /**
     * Constructor.
     */
    explicit AmdGpu(const char *pciId);

    /**
     * Copy constructor.
     */
    AmdGpu(const AmdGpu &other) = delete;

    /**
     * Assignment operator.
     */
    AmdGpu &operator=(const AmdGpu &other) = delete;

    /**
     * Destructor.
     */
    ~AmdGpu() override = default;

    static std::vector<std::string> searchPciIds();

    void refresh() override;

    [[nodiscard]] uint64_t getValue() const override;

    [[nodiscard]] uint16_t getGraphicsUsage() const;

    [[nodiscard]] uint16_t getMediaUsage() const;

    [[nodiscard]] uint16_t getCoreTemperature() const;

    static const constexpr char *AMDGPU_PATH = "/sys/bus/pci/drivers/amdgpu";

private:

    /* Structs taken from MangoHud (https://github.com/flightlessmango/MangoHud/blob/master/src/amdgpu.h) */

    struct GpuMetricsHeader {
        uint16_t structureSize;
        uint8_t formatRevision;
        uint8_t contentRevision;
    };

    struct GpuMetrics13 {
        GpuMetricsHeader header;

        /* Temperature */
        uint16_t temperatureEdge;
        uint16_t temperatureHotspot;
        uint16_t temperatureMemory;
        uint16_t temperatureVrGfx;
        uint16_t temperatureVrSoc;
        uint16_t temperatureVrMemory;

        /* Utilization */
        uint16_t averageGfxActivity;
        uint16_t averageMemoryControllerActivity;
        uint16_t averageVideoActivity;

        /* Power/Energy */
        uint16_t averageSocketPower;
        uint64_t energyAccumulator;

        /* Driver attached timestamp (in ns) */
        uint64_t systemClockCounter;

        /* Average clocks */
        uint16_t averageGfxClockFrequency;
        uint16_t averageSocClockFrequency;
        uint16_t averageUclkFrequency;
        uint16_t averageVclk0Frequency;
        uint16_t averageDclk0Frequency;
        uint16_t averageVclk1Frequency;
        uint16_t averageDclk1Frequency;

        /* Current clocks */
        uint16_t currentGfxClkFrequency;
        uint16_t currentSocClkFrequency;
        uint16_t currentUclkFrequency;
        uint16_t currentVclk0Frequency;
        uint16_t currentDclk0Frequency;
        uint16_t currentVclk1Frequency;
        uint16_t currentDclk1Frequency;

        /* Throttle status */
        uint32_t throttleStatus;

        /* Fans */
        uint16_t currentFanSpeed;

        /* Link width/speed */
        uint16_t pciExpressLinkWidth;
        uint16_t pciExpressLinkSpeed; // in 0.1 GT/s

        uint16_t padding1;

        uint32_t GfxAcitvityAcc;
        uint32_t memoryActivityAcc;

        uint16_t temperatureHbm[4];

        /* PMFW attached timestamp (10ns resolution) */
        uint64_t firmwareTimestamp;

        /* Voltage (mV) */
        uint16_t voltageSoc;
        uint16_t voltageGfx;
        uint16_t voltageMem;

        uint16_t padding2;

        /* Throttle status (ASIC independent) */
        uint64_t independentThrottleStatus;
    } __attribute__ ((packed));

    struct GpuMetrics24 {
        GpuMetricsHeader header;

        /* Temperature */
        uint16_t temperatureGfx; // gfx temperature on APUs
        uint16_t temperatureSoc; // soc temperature on APUs
        uint16_t temperatureCore[8]; // CPU core temperature on APUs
        uint16_t temperatureL3[2];

        /* Utilization */
        uint16_t averageGfxActivity;
        uint16_t averageVideoActivity; // UVD or VCN

        /* Driver attached timestamp (in ns) */
        uint64_t systemClockCounter;

        /* Power/Energy */
        uint16_t averageSocketPower; // dGPU + APU power on A + A platform
        uint16_t averageCpuPower;
        uint16_t averageSocPower;
        uint16_t averageGfxPower;
        uint16_t averageCorePower[8]; // CPU core power on APUs

        /* Average clocks */
        uint16_t averageGfxClkFrequency;
        uint16_t averageSocClkFrequency;
        uint16_t averageUclkFrequency;
        uint16_t averageFclkFrequency;
        uint16_t averageVclkFrequency;
        uint16_t averageDclkFrequency;

        /* Current clocks */
        uint16_t currentGfxClkFrequency;
        uint16_t currentSocClkFrequency;
        uint16_t currentUclkFrequency;
        uint16_t currentFclkFrequency;
        uint16_t currentVclkFrequency;
        uint16_t currentDclkFrequency;
        uint16_t currentCoreClkFrequency[8]; // CPU core clocks
        uint16_t currentL3ClkFrequency[2];

        /* Throttle status (ASIC dependent) */
        uint32_t throttleStatus;

        /* Fans */
        uint16_t fanPwm;

        uint16_t padding[3];

        /* Throttle status (ASIC independent) */
        uint64_t independentThrottleStatus;

        /* Average Temperature */
        uint16_t averageTemperatureGfx; // average gfx temperature on APUs
        uint16_t averageTemperatureSoc; // average soc temperature on APUs
        uint16_t averageTemperatureCore[8]; // average CPU core temperature on APUs
        uint16_t averageTemperatureL3[2];

        /* Power/Voltage (unit: mV) */
        uint16_t averageCpuVoltage;
        uint16_t averageSocVoltage;
        uint16_t averageGfxVoltage;

        /* Power/Current (unit: mA) */
        uint16_t averageCpuCurrent;
        uint16_t averageSocCurrent;
        uint16_t averageGfxCurrent;
    } __attribute__ ((packed));

    std::ifstream metricsFileStream;
    GpuMetricsHeader metricsHeader{};

    uint16_t graphicsUsage = 0;
    uint16_t mediaUsage = 0;
    uint16_t coreTemperature = 0;
};

}

#endif
