cmake_minimum_required(VERSION 3.14)
project(NoobyEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D__DEBUG__")

add_subdirectory(Infrastructure)
add_subdirectory(Core)
add_subdirectory(external)
add_subdirectory(Interfaces)
set_target_properties(Interfaces PROPERTIES LINKER_LANGUAGE CXX)


find_package(OpenGL REQUIRED)

include_directories(
        external/glfw-3.1.2/include/
        external/glm-0.9.7.1/
        external/glew-1.13.0/include/
        external/assimp-3.0.1270/include/
        .
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
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

add_executable(NoobyEngine main.cpp)

target_link_libraries(NoobyEngine
		Core.Graphics
		Infrastructure
        ${ALL_LIBS}
        )