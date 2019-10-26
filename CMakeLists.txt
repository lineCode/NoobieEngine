cmake_minimum_required(VERSION 3.14)
project(NoobyEngine)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D__DEBUG__")

add_executable(Engine main.cpp)

add_subdirectory(Core/Infrastructure)
add_subdirectory(Core/Renderer)
add_subdirectory(Core/Primitives)
add_subdirectory(external)
add_subdirectory(Interfaces)
add_subdirectory(Programs)
add_subdirectory(Examples)
add_subdirectory(external/soil2)

find_package(OpenGL REQUIRED)

include_directories(
        Programs/include
        external/glfw-3.3/include/
        external/glm-0.9.7.1/
        external/glew-2.1.0/include/
        external/assimp-3.0.1270/include/
        external/soil2/src
        .
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        GLFW
        GLEW_210
        SOIL
        )

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

target_link_libraries(Engine
        core.renderer
        core.primitives
        core.infrastructure
        ${ALL_LIBS}
        )

### Texture Example ###

add_executable(Texture_Example
        Examples/src/Texture.cpp
        Programs/src/CubeProgram.cpp
        Programs/src/BaseProgram.cpp
        )

include_directories(Core)

target_link_libraries(Texture_Example
        core.renderer
        core.primitives
        core.infrastructure
        ${ALL_LIBS}
        )

### Sphere Example ###
add_executable(Sphere_Example
        Examples/src/Sphere.cpp
        Programs/src/SphereProgram.cpp
        Programs/src/BaseProgram.cpp
        )
include_directories(Core)
target_link_libraries(Sphere_Example
        core.renderer
        core.primitives
        core.infrastructure
        ${ALL_LIBS}
        )