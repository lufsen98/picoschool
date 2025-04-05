# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ludvig/ws/edu-ws/embedded-edu/picoschool/chaosblink/build/_deps/picotool-src"
  "/home/ludvig/ws/edu-ws/embedded-edu/picoschool/chaosblink/build/_deps/picotool-build"
  "/home/ludvig/ws/edu-ws/embedded-edu/picoschool/chaosblink/build/_deps"
  "/home/ludvig/ws/edu-ws/embedded-edu/picoschool/chaosblink/build/picotool/tmp"
  "/home/ludvig/ws/edu-ws/embedded-edu/picoschool/chaosblink/build/picotool/src/picotoolBuild-stamp"
  "/home/ludvig/ws/edu-ws/embedded-edu/picoschool/chaosblink/build/picotool/src"
  "/home/ludvig/ws/edu-ws/embedded-edu/picoschool/chaosblink/build/picotool/src/picotoolBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ludvig/ws/edu-ws/embedded-edu/picoschool/chaosblink/build/picotool/src/picotoolBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/ludvig/ws/edu-ws/embedded-edu/picoschool/chaosblink/build/picotool/src/picotoolBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
