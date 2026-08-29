cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(gb_emulator)

add_executable(gb_emulator src/main.c src/bus.c)
