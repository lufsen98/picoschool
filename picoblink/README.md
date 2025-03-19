# PICO blink external led.

## Hardware
1. 1 Raspberry Pico w 2. 2 jumpers
3. 1 220ohm r4
4. 1 led

## Download Libraries And set path
```bash
   git clone https://github.com/raspberrypi/pico-sdk
   export PICO_SDK_PATH=~/your_path_to_pico-sdk/external/pico_sdk_import.cmake
```
## Setup project folder 
```bash
   mkdir pico_blink
   touch CMakeLists.txt
   touch main.cpp
```
## Setup CMakeLists.txt

```cmake
   cmake_minimum_required(VERSION 3.16)
   # Set what board you are using
   set(PICO_BOARD pico_w)

   # Include the path to your pico_sdk_import.cmake
   include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

   # Define the project
   project(blink C CXX ASM)

   # Set the C and C++ standards
   set(CMAKE_C_STANDARD 11)
   set(CMAKE_CXX_STANDARD 17)

   # intialize the pico sdk library
   pico_sdk_init()

   # Set name of executable file
   add_executable(${PROJECT_NAME} 1)
   
   # Enable USB for the executable
   pico_enable_stdio_usb(${PROJECT_NAME} 1)

   # Add extra outputs (UF2 file to load on pico)
   pico_add_extra_outputs(${PROJECT_NAME})

   # Link the necessary libraries from the pico-sdk

   target_link_libraries(${PROJECT-NAME}
           pico_stdlib
   )
```


## Write your main.cpp src

```cpp
   #include <pico/stdio.h>

   int main() {
   // initialize gpio variable and set direction





