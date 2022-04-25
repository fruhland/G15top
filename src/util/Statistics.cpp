#include "Statistics.h"

namespace G15::Util {

void Statistics::refresh() {
    glibtop_get_mem(&memoryInfo);
}

uint64_t Statistics::getTotalMemory() const {
    return memoryInfo.total;
}

uint64_t Statistics::getUsedMemory() const {
    return memoryInfo.user;
}

}