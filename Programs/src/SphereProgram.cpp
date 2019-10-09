//
// Created by Roberto on 2019-09-28.
//


#include "SphereProgram.h"

SphereProgram::SphereProgram(std::unique_ptr<GLResource> program)
    :BaseProgram(std::move(program))
{

}

void SphereProgram::addObject(std::shared_ptr<SphereObject> object)
{
    m_Objects.push_back(object);
}

void SphereProgram::onRender()
{

}