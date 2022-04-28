#ifndef G15TOP_MEMORYMONITORABLE_H
#define G15TOP_MEMORYMONITORABLE_H

#include <cstdint>
#include "Monitorable.h"

namespace G15::Monitor {

class MemoryMonitorable : public Monitorable {

public:
    /**
     * Constructor.
     */
    explicit MemoryMonitorable() = default;

    /**
     * Copy constructor.
     */
    MemoryMonitorable(const MemoryMonitorable &other) = delete;

    /**
     * Assignment operator.
     */
    MemoryMonitorable &operator=(const MemoryMonitorable &other) = delete;

    /**
     * Destructor.
     */
    ~MemoryMonitorable() = default;

    void refresh() override = 0;

    [[nodiscard]] virtual uint64_t getTotal() const = 0;

    [[nodiscard]] virtual uint64_t getUsed() const = 0;
};

}

#endif
