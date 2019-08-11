//
// Created by Rob on 2019-08-11.
//

#ifndef NOOBYENGINE_CUBEPROGRAM_H
#define NOOBYENGINE_CUBEPROGRAM_H

#include "Infrastructure/GLResource.h"
#include "Infrastructure/GLFWContext.h"
#include "Infrastructure/GLSafe.h"
#include "Interfaces/IRenderable.h"
#include "Core/include/Camera.h"
#include "Core/include/DrawableObject.h"

class CubeProgram : public IRenderable
{
public:
    CubeProgram(
        std::unique_ptr<GLResource> program,
        GLFWwindow * window,
        std::shared_ptr<Camera> camera,
        std::shared_ptr<DrawableObject> cubeObject);
    void onRender() override;
    GLuint programId();
private:
    std::unique_ptr<GLResource> m_Program;
    GLFWwindow * m_GlfwWindow;
    std::shared_ptr<Camera> m_Camera;
    std::shared_ptr<DrawableObject> m_CubeObject;
};


#endif //NOOBYENGINE_CUBEPROGRAM_H
