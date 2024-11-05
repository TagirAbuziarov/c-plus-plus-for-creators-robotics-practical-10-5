cmake_minimum_required(VERSION 3.16)
project(
    vector_3d
    VERSION 0.0.1
    DESCRIPTION "vector"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_BUILD_TYPE Debug)

# pybind11 method: use New FindPython mode
# https://pybind11.readthedocs.io/en/stable/cmake/index.html#new-findpython-mode
find_package(Python COMPONENTS Interpreter Development REQUIRED) 
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/pybind11)

# Команда, генерирующая Python пакет из cpp кода
pybind11_add_module(vector_3d src/vector_export.cpp src/vector_3d.cpp)

# Директории, в которых компилятор ищет h/hpp файлы
target_include_directories(vector_3d
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

