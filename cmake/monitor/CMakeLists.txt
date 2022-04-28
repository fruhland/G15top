# Copyright (C) 2022 Fabian Ruhland <ruhland@hhu.de>
#
# This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
# License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>

cmake_minimum_required(VERSION 3.10)

project(monitor)
message(STATUS "Project " ${PROJECT_NAME})

include_directories(${HHUOS_SRC_DIR})

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(LIBGTOP REQUIRED libgtop-2.0)

# Set source files
set(SOURCE_FILES
        ${G15TOP_SRC_DIR}/monitor/Clock.cpp
        ${G15TOP_SRC_DIR}/monitor/CpuUsage.cpp
        ${G15TOP_SRC_DIR}/monitor/Memory.cpp
        ${G15TOP_SRC_DIR}/monitor/Monitor.cpp
        ${G15TOP_SRC_DIR}/monitor/Swap.cpp
        ${G15TOP_SRC_DIR}/monitor/ValueMonitorable.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${LIBGTOP_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} util gtop-2.0)