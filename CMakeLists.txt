project(qttestproject)
cmake_minimum_required(VERSION 3.0)

include(FindPkgConfig)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND COMPILE_OPTIONS
  $<$<COMPILE_LANGUAGE:C>:-std=c99>
  $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
  -Wall
  -Wextra
  -Wpedantic
  -Wunused
  -Wshadow
  -Wundef
  -Wuninitialized
  -Wredundant-decls
  -Wcast-align
  -Winit-self
  -Wmissing-include-dirs
  -Wmissing-declarations
  -Wstrict-overflow=2
  -Wunused-parameter
  -Wformat=2
  -Wdisabled-optimization
  $<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>
  $<$<COMPILE_LANGUAGE:CXX>:-Wno-old-style-cast>
  $<$<COMPILE_LANGUAGE:CXX>:-fpermissive>
)

add_compile_options(${COMPILE_OPTIONS})

pkg_check_modules(GLIB glib-2.0)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
set(QT_LIBRARIES Qt6::Core Qt6::Gui Qt6::Widgets)

add_subdirectory(src)
