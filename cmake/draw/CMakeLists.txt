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

project(draw)
message(STATUS "Project " ${PROJECT_NAME})

include_directories(${HHUOS_SRC_DIR})

# Set source files
set(SOURCE_FILES
        ${G15TOP_SRC_DIR}/draw/Bar.cpp
        ${G15TOP_SRC_DIR}/draw/Drawable.cpp
        ${G15TOP_SRC_DIR}/draw/Screen.cpp
        ${G15TOP_SRC_DIR}/draw/Text.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

add_subdirectory(clock)
add_subdirectory(memory)

target_link_libraries(${PROJECT_NAME} monitor util g15render g15daemon_client)