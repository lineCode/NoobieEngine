//
// Created by Rob on 2019-08-27.
//

#include "BaseProgram.h"

void BaseProgram::onRender()
{
    GLCall(glUseProgram(m_Program->resourceId()));
}

BaseProgram::BaseProgram(std::shared_ptr<Camera> camera) :
 m_Camera(camera)
{

}