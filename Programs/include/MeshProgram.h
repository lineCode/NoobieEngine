#ifndef MESHPROGRAM_H
#define MESHPROGRAM_H


#include "BaseProgram.h"

class MeshProgram : public BaseProgram
{
public:
    MeshProgram(std::shared_ptr<GLResource> program);
    GLint projectionMatrixLocation();
    GLint modelViewMatrixLocation();
};


#endif // MESHPROGRAM_H
