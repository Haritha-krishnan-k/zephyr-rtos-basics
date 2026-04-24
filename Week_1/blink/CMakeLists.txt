cmake_minimum_version(3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(blink)

target_source(app PRIVATE src/main.c)

