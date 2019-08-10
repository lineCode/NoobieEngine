target_sources(noobyLib
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

target_compile_definitions(noobyLib PUBLIC USE_NOOBY_LIB)
target_include_directories(noobyLib PUBLIC ${CMAKE_CURRENT_LIST_DIR})