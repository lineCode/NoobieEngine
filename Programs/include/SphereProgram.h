//
// Created by Roberto on 2019-09-28.
//


#ifndef NOOBYENGINE_SPHEREPROGRAM_H
#define NOOBYENGINE_SPHEREPROGRAM_H

#include "BaseProgram.h"
#include "Core/Primitives/include/SphereObject.h"

class SphereProgram : public BaseProgram
{
public:
    SphereProgram(std::unique_ptr<GLResource> program);
};


#endif //NOOBYENGINE_SPHEREPROGRAM_H
