cmake_minimum_required(VERSION 3.14)
project(core.graphics VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_definitions(
    -DTW_STATIC
    -DTW_NO_LIB_PRAGMA
    -DTW_NO_DIRECT3D
    -DGLEW_STATIC
    -D_CRT_SECURE_NO_WARNINGS
)

add_library(Core.Graphics 
		include/VertexBuffer.h
        include/VertexArray.h
        include/Renderer.h
        include/Mesh.h
		include/Camera.h
		include/DrawableObject.h
		include/VertexBufferScope.h
		include/BufferMode.h
		include/TextureScope.h
		src/TextureScope.cpp
		src/VertexBufferScope.cpp
		src/DrawableObject.cpp
		src/Camera.cpp
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
		../external/glfw-3.3/include/
        ../external/glm-0.9.7.1/
        ../external/glew-2.1.0/include/
		.
		)