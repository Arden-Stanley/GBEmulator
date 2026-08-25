cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(gb_emulator)

add_executable(gbe src/main.cpp  "src/gb_memory.cpp")