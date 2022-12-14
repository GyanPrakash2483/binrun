cmake_minimum_required(VERSION 3.25.0)
project(binrun)
include_directories(include/)
add_executable(binrun src/binrun.c src/resetstring.c)
install(TARGETS binrun DESTINATION /data/data/com.termux/files/usr/bin)

find_program(termux-elf-cleaner termux-elf-cleaner REQUIRED)
find_program(chmod chmod REQUIRED)
add_custom_command(TARGET binrun
        POST_BUILD
        COMMAND termux-elf-cleaner binrun)
