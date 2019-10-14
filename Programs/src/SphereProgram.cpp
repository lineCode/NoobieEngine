//
// Created by Roberto on 2019-09-28.
//


#include "SphereProgram.h"
#include "Infrastructure/include/GLSafe.h"

SphereProgram::SphereProgram(std::shared_ptr<GLResource> program)
    :BaseProgram(program)
{

}

GLuint SphereProgram::projectionMatrixLocation()
{
    GLint projLoc;
    GLCall(projLoc = glGetUniformLocation(m_program->resourceId(), "proj_matrix"));
    return projLoc;
}

GLuint SphereProgram::modelViewMatrixLocation()
{
    GLint mvLoc;
    GLCall(mvLoc = glGetUniformLocation(m_program->resourceId(), "mv_matrix"));
    return mvLoc;
}