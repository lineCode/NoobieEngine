target_sources(noobyLib
        PRIVATE
        GLFWContext.cpp
        ShaderLoader.cpp
        FileUtils.cpp
        PUBLIC
        ShaderLoader.h
        GLFWContext.h
        FileUtils.h
        )


target_compile_definitions(noobyLib PUBLIC USE_NOOBY_LIB)
target_include_directories(noobyLib PUBLIC ${CMAKE_CURRENT_LIST_DIR})