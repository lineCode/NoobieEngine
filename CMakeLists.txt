cmake_minimum_required(VERSION 3.14)
project(NoobyEngine)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D__DEBUG__")

add_executable(NoobyEngine main.cpp)

add_subdirectory(Infrastructure)
add_subdirectory(Core)
add_subdirectory(external)
add_subdirectory(Interfaces)
add_subdirectory(Programs)
add_subdirectory(Samples)
add_subdirectory(external/soil2)

find_package(OpenGL REQUIRED)

include_directories(
		Programs/Include
        external/glfw-3.3/include/
        external/glm-0.9.7.1/
        external/glew-2.1.0/include/
        external/assimp-3.0.1270/include/
		external/soil2/src
        .
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
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

FILE(COPY SimpleTransform.vertexshader DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY SingleColor.fragmentshader DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY MatrixUtil.glsl DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY vertShader.glsl DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY Samples/images/brick1.jpg DESTINATION "${CMAKE_BINARY_DIR}")


target_link_libraries(NoobyEngine
		Core.Graphics
		Infrastructure
        ${ALL_LIBS}
        )