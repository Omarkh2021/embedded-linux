cmake_minimum_required(VERSION 3.10)
project(iot-server)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Network)

set(SOURCES src/server.cpp)

add_executable(server ${SOURCES})

target_link_libraries(server Qt5::Core Qt5::Widgets Qt5::Network)
