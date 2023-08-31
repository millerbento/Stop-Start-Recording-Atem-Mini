cmake_minimum_required(VERSION 3.12)
project(SwitcherPython)

# Specify the path to your Pybind11 directory
set(PYBIND11_DIR /Users/miller/.pyenv/versions/3.9.17/lib/python3.9/site-packages)

# Specify the relative path to the Blackmagic Design SDK include directory
include_directories(${CMAKE_SOURCE_DIR}/blackmagic_api/mac_os/include)

find_package(pybind11 REQUIRED)

add_library(switcher MODULE switcher_bindings.cpp SwitcherConnection.cpp)

target_link_libraries(switcher PRIVATE pybind11::module)