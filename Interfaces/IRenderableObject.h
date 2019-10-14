//
// Created by Rob on 2019-07-22.
//

#ifndef NOOBYENGINE_IRenderableObject_H
#define NOOBYENGINE_IRenderableObject_H

#include "IRenderable.h"
#include <glm/glm.hpp>

class IRenderableObject : public IRenderable
{
public:
    virtual void setViewMatrix(glm::mat4 viewMatrix) = 0;
    virtual void setProjectionMatrix(glm::mat4 projectionMatrix) = 0;
};
#endif //IRenderableObject
