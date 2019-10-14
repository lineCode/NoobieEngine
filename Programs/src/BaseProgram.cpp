//
// Created by Rob on 2019-08-27.
//

#include "BaseProgram.h"

BaseProgram::BaseProgram(std::shared_ptr<GLResource> program) :
    m_program(std::move(program))
{

}

void BaseProgram::useProgram()
{
    GLCall(glUseProgram(m_program->resourceId()));
}

GLuint BaseProgram::programId()
{
    return m_program->resourceId();
}