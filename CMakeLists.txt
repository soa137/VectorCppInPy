cmake_minimum_required(VERSION 3.16)
project(
    vector2py
    VERSION 0.0.1
    DESCRIPTION "Vector3D cpp to py"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Python COMPONENTS Interpreter Development REQUIRED)

add_subdirectory(libs/pybind11)

FILE(GLOB PYBIND_SRC
vector2py
src/main.cpp
)

pybind11_add_module(vector2py ${PYBIND_SRC})
