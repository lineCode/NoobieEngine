//
// Created by Rob on 2019-08-27.
//

#ifndef NOOBYENGINE_BASEPROGRAM_H
#define NOOBYENGINE_BASEPROGRAM_H

#include "../../Infrastructure/include/GLResource.h"
#include "../../Infrastructure/include/GLSafe.h"
#include <glm/glm.hpp>

class BaseProgram
{
public:
    BaseProgram(std::shared_ptr<GLResource> program);
    void setMatrix(std::string uniformName, glm::mat4 matrix);
    GLuint programId();
    void useProgram();
protected:
    std::shared_ptr<GLResource> m_program;
};


#endif //NOOBYENGINE_BASEPROGRAM_H
