#ifndef MESHPROGRAM_H
#define MESHPROGRAM_H


#include "BaseProgram.h"
#include "Core/Primitives/include/SphereObject.h"

class MeshProgram : public BaseProgram
{
public:
    MeshProgram(std::shared_ptr<GLResource> program);
    GLint projectionMatrixLocation();
    GLint modelViewMatrixLocation();
};


#endif // MESHPROGRAM_H
