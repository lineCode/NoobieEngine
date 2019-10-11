//
// Created by Rob on 2019-08-27.
//

#include "BaseProgram.h"

BaseProgram::BaseProgram(std::shared_ptr<GLResource> program) :
    m_Program(std::move(program))
{

}

void BaseProgram::useProgram()
{
    GLCall(glUseProgram(m_Program->resourceId()));
}
