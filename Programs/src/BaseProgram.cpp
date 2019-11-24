//
// Created by Rob on 2019-08-27.
//

#include "BaseProgram.h"
#include "external/glm-0.9.7.1/glm/gtc/type_ptr.hpp"


BaseProgram::BaseProgram(std::shared_ptr<GLResource> program) :
    m_program(std::move(program))
{

}

void BaseProgram::useProgram()
{
    //todo should move to constructor?
    GLCall(glUseProgram(m_program->resourceId()));
}

GLuint BaseProgram::programId()
{
    return m_program->resourceId();
}

void BaseProgram::setMatrix(std::string uniformName, glm::mat4 matrix)
{
    GLint mvLoc;
    GLCall(mvLoc = glGetUniformLocation(m_program->resourceId(), uniformName.c_str()))
    GLCall(glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(matrix)))
}