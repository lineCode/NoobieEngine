//
// Created by Rob on 2019-07-14.
//
#include "include/GLUtils.h"
#include <GL/glew.h>
#include <vector>

void checkCompilationResult(unsigned int shaderId) {
    int InfoLogLength;
    GLint Result = GL_FALSE;
    // Check Vertex Shader
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 )
    {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(shaderId, InfoLogLength, nullptr, &VertexShaderErrorMessage[0]);
        printf("%s\n", &VertexShaderErrorMessage[0]);
    }
}

void checkLinkerResult(unsigned int programId) {
    int InfoLogLength;
    GLint Result = GL_FALSE;
    glGetProgramiv(programId, GL_LINK_STATUS, &Result);
    glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(programId, InfoLogLength, nullptr, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }
}