//
// Created by Rob on 2019-08-11.
//

#ifndef NOOBYENGINE_CUBEPROGRAM_H
#define NOOBYENGINE_CUBEPROGRAM_H

#include "../../Infrastructure/include/GLFWContext.h"
#include "../../Infrastructure/include/GLResource.h"
#include "Programs/include/BaseProgram.h"
#include "Core/Primitives/include/DrawableObject.h"
#include "Camera.h"

class CubeProgram : public BaseProgram
{
public:
    CubeProgram(std::shared_ptr<GLResource> program, std::shared_ptr<Camera> camera);
    GLuint programId();
    //remove
    void addObject(std::shared_ptr<DrawableObject> object);
private:
    std::vector<std::shared_ptr<DrawableObject>> m_Objects;
    std::shared_ptr<Camera> m_Camera;
};


#endif //NOOBYENGINE_CUBEPROGRAM_H
