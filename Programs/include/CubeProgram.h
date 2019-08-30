//
// Created by Rob on 2019-08-11.
//

#ifndef NOOBYENGINE_CUBEPROGRAM_H
#define NOOBYENGINE_CUBEPROGRAM_H

#include "Infrastructure/GLFWContext.h"
#include "Infrastructure/GLResource.h"
#include "Programs/include/BaseProgram.h"
#include "Core/include/DrawableObject.h"

class CubeProgram : public BaseProgram
{
public:
    CubeProgram(std::shared_ptr<Camera> camera);
    void onRender() override;
    GLuint programId();
    void addObject(std::shared_ptr<DrawableObject> object);
private:
    std::vector<std::shared_ptr<DrawableObject>> m_Objects;
};


#endif //NOOBYENGINE_CUBEPROGRAM_H
