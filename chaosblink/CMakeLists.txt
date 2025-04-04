cmake_minimum_required(VERSION 3.16)
set(PICO_BOARD pico_w)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(chaosblink C CXX ASM)

pico_sdk_init()
add_executable(${PROJECT_NAME} main2.cpp)
pico_add_extra_outputs(${PROJECT_NAME})
pico_enable_stdio_usb(${PROJECT_NAME} 1)

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    pico_rand
    
)



