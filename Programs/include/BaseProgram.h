//
// Created by Rob on 2019-08-27.
//

#ifndef NOOBYENGINE_BASEPROGRAM_H
#define NOOBYENGINE_BASEPROGRAM_H

#include "../../Infrastructure/include/GLResource.h"
#include "../../Infrastructure/include/GLSafe.h"

class BaseProgram
{
public:
    BaseProgram(std::unique_ptr<GLResource> program);
    void useProgram();
protected:
    std::unique_ptr<GLResource> m_Program;
};


#endif //NOOBYENGINE_BASEPROGRAM_H
