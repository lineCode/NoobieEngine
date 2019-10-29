cmake_minimum_required(VERSION 3.14)
project(core.infrastructure VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(core.infrastructure)

target_sources(core.infrastructure
        PRIVATE
		src/GLUtils.cpp
		src/GLSafe.cpp
		src/GLFWContext.cpp
		src/ShaderLoader.cpp
		src/FileUtils.cpp
		src/AssimpModelLoader.cpp
		src/GLResource.cpp
		src/FileTextureLoader.cpp
        PUBLIC
		include/FileTextureLoader.h
		include/GLSafe.h
		include/GLUtils.h
		include/ShaderLoader.h
		include/GLFWContext.h
		include/FileUtils.h
		include/AssimpModelLoader.h
		include/GLResource.h
        )
		
add_definitions(
    -DTW_STATIC
    -DTW_NO_LIB_PRAGMA
    -DTW_NO_DIRECT3D
    -DGLEW_STATIC
    -D_CRT_SECURE_NO_WARNINGS
)

include_directories("../../external/assimp-5.0/include")
include_directories("../../external/glew-2.1.0/include")
include_directories("../../external/glfw-3.3/include")
include_directories("../../external/glm-0.9.7.1")
include_directories("../../")

target_compile_definitions(core.infrastructure PUBLIC USE_NOOBY_LIB)
target_include_directories(core.infrastructure PUBLIC .)