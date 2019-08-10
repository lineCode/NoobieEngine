add_library(Infrastructure)

target_sources(Infrastructure
        PRIVATE
        GLUtils.cpp
        GLSafe.cpp
        GLFWContext.cpp
        ShaderLoader.cpp
        FileUtils.cpp
        AssimpModelLoader.cpp
		GLResource.cpp
        PUBLIC
        GLSafe.h
        GLUtils.h
        ShaderLoader.h
        GLFWContext.h
        FileUtils.h
        AssimpModelLoader.h
		GLResource.h
        )
		
include_directories("../external/assimp-3.0.1270/include/")
include_directories("../external/glew-1.13.0/include/")
include_directories("../external/glfw-3.1.2/include/")
include_directories("../external/glm-0.9.7.1/")

target_compile_definitions(Infrastructure PUBLIC USE_NOOBY_LIB)
target_include_directories(Infrastructure PUBLIC ${CMAKE_CURRENT_LIST_DIR})