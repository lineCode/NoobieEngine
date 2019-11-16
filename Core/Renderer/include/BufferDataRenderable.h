#pragma once

#include "VertexBufferBase.h"
#include "../../Infrastructure/include/GLResource.h"
#include "../../Infrastructure/include/GLSafe.h"
#include <GL/glew.h>
#include <vector>
#include <memory>

class BufferDataRenderable : public VertexBufferBase
{
public:
    BufferDataRenderable() = default;
    void onRender() override;

    template<typename T> void makeBuffer(
        const std::vector<T>& vertices,
        unsigned int elementsPerComponent,
        GLenum bufferType);
};

#include "BufferDataRenderable.hpp"