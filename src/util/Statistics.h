#ifndef G15TOP_STATISTICS_H
#define G15TOP_STATISTICS_H

#include <cstdint>
#include <glibtop/mem.h>

namespace G15::Util {

class Statistics {

public:

    /**
     * Constructor.
     */
    explicit Statistics() = default;

    /**
     * Copy constructor.
     */
    Statistics(const Statistics &other) = delete;

    /**
     * Assignment operator.
     */
    Statistics &operator=(const Statistics &other) = delete;

    /**
     * Destructor.
     */
    ~Statistics() = default;

    void refresh();

    [[nodiscard]] uint64_t getTotalMemory() const;

    [[nodiscard]] uint64_t getUsedMemory() const;

private:

    glibtop_mem memoryInfo{};
};

}

#endif
