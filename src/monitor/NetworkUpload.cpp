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

#include "NetworkUpload.h"

namespace G15::Monitor {

NetworkUpload::NetworkUpload(const char *interface) :
        interface(interface) {}

void NetworkUpload::refresh() {
    lastNetworkInfo = currentNetworkInfo;
    glibtop_get_netload(&currentNetworkInfo, interface.c_str());
}

uint64_t NetworkUpload::getValue() const {
    return currentNetworkInfo.bytes_out - lastNetworkInfo.bytes_out;
}

}