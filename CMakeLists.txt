cmake_minimum_required(VERSION 3.25.0)
project(binrun)
include_directories(include/)
add_executable(binrun src/binrun.c src/resetstring.c)
