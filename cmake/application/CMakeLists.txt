cmake_minimum_required(VERSION 3.7)

project(application)
message(STATUS "Project " ${PROJECT_NAME})

include_directories(${HHUOS_SRC_DIR})

# Set source files
set(SOURCE_FILES
        ${G15TOP_SRC_DIR}/main.cpp)

add_executable(g15top ${SOURCE_FILES})

target_link_libraries(g15top g15render g15daemon_client)