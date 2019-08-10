cmake_minimum_required(VERSION 3.14)
project(core.graphics VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(Core.Graphics 
		src/VertexBuffer.cpp
        src/VertexArray.cpp
        src/Renderer.cpp
        src/Mesh.cpp)

target_include_directories(Core.Graphics
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

include_directories(
		../external/glfw-3.1.2/include/
        ../external/glm-0.9.7.1/
        ../external/glew-1.13.0/include/
		.
		)