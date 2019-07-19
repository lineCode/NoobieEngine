target_sources(noobyLib
        PRIVATE
        GLUtils.cpp
        GLSafe.cpp
        GLFWContext.cpp
        ShaderLoader.cpp
        FileUtils.cpp
        PUBLIC
        GLSafe.h
        GLUtils.h
        ShaderLoader.h
        GLFWContext.h
        FileUtils.h
        )


target_compile_definitions(noobyLib PUBLIC USE_NOOBY_LIB)
target_include_directories(noobyLib PUBLIC ${CMAKE_CURRENT_LIST_DIR})