//
// Created by Rob on 2019-07-13.
//

#ifndef GLSafe_h
#define GLSafe_h

#include <iostream>
#include <GL/glew.h>
#include "../external/debugbreak.h"

void GLClearError();
bool GLCheckError(const char *file, const char * function, int line);

#ifdef __DEBUG__
#define ASSERT(x) if(!(x)) debug_break();
#define GLCall(x) GLClearError();\
                x;\
                ASSERT(GLCheckError(__FILE__, #x, __LINE__))
#else
#define GLCall(x) x;
#endif
#endif