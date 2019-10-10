cmake_minimum_required(VERSION 3.14)
project(core.primitives VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

dd_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

add_library(core.primitives
        include/DrawableObject.h
        include/SphereObject.h
        src/SphereObject.cpp
        src/DrawableObject.cpp)

target_include_directories(core.primitives
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        src
        )


include_directories(
        add_compile_definitions../../external/glfw-3.3/include
        ../../external/glm-0.9.7.1
        ../../external/glew-2.1.0/include
        ..
        ../..
)