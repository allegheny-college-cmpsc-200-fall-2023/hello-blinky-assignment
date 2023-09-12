cmake_minimum_required(VERSION 3.18)
include($ENV{PICO_SDK_PATH}\\external\\pico_sdk_import.cmake)
project(blink LANGUAGES C CXX ASM)

add_executable(blink blink.c)

set_target_properties(${PROJECT_NAME} PROPERTIES
  CMAKE_C_STANDARD 11
  CMAKE_CXX_STANDARD 17
)

set(PICO_BOARD pico_w)

pico_sdk_init()

target_link_libraries(${PROJECT_NAME} 
        pico_stdlib
        pico_cyw43_arch_none
)

pico_add_extra_outputs(${PROJECT_NAME})

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)