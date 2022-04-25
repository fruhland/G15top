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

# Set version
execute_process(COMMAND git describe --tags --abbrev=0 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE G15TOP_VERSION ERROR_QUIET)
string(STRIP "${G15TOP_VERSION}" G15TOP_VERSION)
if (G15TOP_VERSION STREQUAL "")
    set(G15TOP_VERSION "v0.0.0")
endif ()

# Set git revision
execute_process(COMMAND git log -1 --format=%h --date=short HEAD WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE G15TOP_GIT_REV ERROR_QUIET)
string(STRIP "${G15TOP_GIT_REV}" G15TOP_GIT_REV)
if (G15TOP_GIT_REV STREQUAL "")
    set(G15TOP_GIT_REV "not available")
endif ()

# Set git branch
execute_process(COMMAND git rev-parse --abbrev-ref HEAD WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        OUTPUT_VARIABLE G15TOP_GIT_BRANCH ERROR_QUIET)
string(STRIP "${G15TOP_GIT_BRANCH}" G15TOP_GIT_BRANCH)
if (G15TOP_GIT_BRANCH STREQUAL "")
    set(G15TOP_GIT_BRANCH "unknown")
endif ()

# Set build date
string(TIMESTAMP G15TOP_BUILD_DATE "%Y-%m-%d %H:%M:%S")

# Print build information
message("g15top ${G15TOP_VERSION} - git ${G15TOP_GIT_REV}, build date: ${G15TOP_BUILD_DATE}")

# Set source directory variables
set(G15TOP_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/..")
set(G15TOP_SRC_DIR "${G15TOP_ROOT_DIR}/src")
set(G15TOP_RES_DIR "${G15TOP_ROOT_DIR}/res")

# Set output directory variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Force out of source build
message(STATUS "Force out of source build check...")
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" insource)
if (insource)
    message(FATAL_ERROR "Please do not build in your source dir. Use a dedicated build folder!")
endif ()

# Set preprocessor defines
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}\
    -DG15TOP_VERSION='${G15TOP_VERSION}'\
    -DG15TOP_GIT_REV='${G15TOP_GIT_REV}'\
    -DG15TOP_GIT_BRANCH='${G15TOP_GIT_BRANCH}'\
    -DG15TOP_BUILD_DATE='${G15TOP_BUILD_DATE}'")

# Add subdirectories
add_subdirectory(g15top)
add_subdirectory(draw)
add_subdirectory(util)