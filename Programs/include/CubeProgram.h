//
// Created by Rob on 2019-08-11.
//

#ifndef NOOBYENGINE_CUBEPROGRAM_H
#define NOOBYENGINE_CUBEPROGRAM_H

#include "Infrastructure/GLFWContext.h"
#include "Infrastructure/GLResource.h"
#include "Infrastructure/GLSafe.h"
#include "Interfaces/IRenderable.h"
#include "Core/include/Camera.h"
#include "Core/include/DrawableObject.h"

class CubeProgram : public IRenderable
{
public:
    CubeProgram(
        std::unique_ptr<GLResource> program,
        std::shared_ptr<Camera> camera);
    void onRender() override;
    GLuint programId();
    void addObject(std::shared_ptr<DrawableObject> object);
private:
    std::vector<std::shared_ptr<DrawableObject>> m_Objects;
    std::unique_ptr<GLResource> m_Program;
    std::shared_ptr<Camera> m_Camera;
};


#endif //NOOBYENGINE_CUBEPROGRAM_H
