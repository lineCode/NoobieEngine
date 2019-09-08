//
// Created by Rob on 2019-08-27.
//

#ifndef NOOBYENGINE_BASEPROGRAM_H
#define NOOBYENGINE_BASEPROGRAM_H

#include "Interfaces/IRenderable.h"
#include "Infrastructure/GLResource.h"
#include "Infrastructure/GLSafe.h"
#include "Core/include/Camera.h"

class BaseProgram : public IRenderable
{
public:
    BaseProgram(std::unique_ptr<GLResource> program, std::shared_ptr<Camera> camera);
public:
    virtual void onRender();
protected:
    std::unique_ptr<GLResource> m_Program;
    std::shared_ptr<Camera> m_Camera;
};


#endif //NOOBYENGINE_BASEPROGRAM_H
