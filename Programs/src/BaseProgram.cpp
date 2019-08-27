//
// Created by Rob on 2019-08-27.
//

#include "BaseProgram.h"

void BaseProgram::onRender()
{
    GLCall(glUseProgram(m_Program->resourceId()));
}

BaseProgram::BaseProgram(std::unique_ptr<GLResource> program, std::shared_ptr<Camera> camera):
m_Program(std::move(program)), m_Camera(camera)
{

}
