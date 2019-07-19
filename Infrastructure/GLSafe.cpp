//
// Created by Rob on 2019-07-16.
//

#include "GLSafe.h"

void GLClearError()
{
    while(glGetError() != GL_NO_ERROR);
}

bool GLCheckError(const char *file, const char * function, int line)
{
    if(GLenum err = glGetError())
    {
        std::cout<<"[OpenGL ERROR] "<< "(0x" <<std::hex<<err<<std::dec<<")"<<std::endl;
        std::cout<<file<<":"<<line<<" "<<function<<std::endl;
        return false;
    }

    return true;
}