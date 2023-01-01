cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(wireframe_clock
  wireframe_clock.c
)

pico_enable_stdio_usb(wireframe_clock 1)
pico_enable_stdio_uart(wireframe_clock 1)

pico_add_extra_outputs(wireframe_clock)

# add_subdirectory(extern/pico-ssd1306)

target_link_libraries(wireframe_clock pico_stdlib hardware_gpio) #  pico-ssd1306