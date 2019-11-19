#pragma once

#include "Interfaces/IRenderableObject.h"
#include <GL/glew.h>

class PositionalLightObject : public IRenderableObject
{
public:
    virtual void onRender() override;
    virtual void setViewMatrix(glm::mat4 viewMatrix) override;
    virtual void setProjectionMatrix(glm::mat4 projectionMatrix) override;
private:
    GLuint m_globalAmbLoc;
    GLuint m_ambLoc;
    GLuint m_diffLoc;
    GLuint m_specLoc;
    GLuint m_posLoc;
};