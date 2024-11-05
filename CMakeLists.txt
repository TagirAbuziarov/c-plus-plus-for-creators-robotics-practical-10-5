cmake_minimum_required(VERSION 3.16)
project(
    vector_3d
    VERSION 0.0.1
    DESCRIPTION "Matrix class"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

set(sources 
    src/vector_3d.cpp
    src/main.cpp
)

# Добавляет target: исполняемый файл
add_executable(${PROJECT_NAME} ${sources})

# Директории, в которых компилятор ищет h/hpp файлы
target_include_directories(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

