#pragma once

#include "VertexBufferBase.h"
#include "../../Infrastructure/include/GLResource.h"
#include "../../Infrastructure/include/GLSafe.h"
#include <GL/glew.h>
#include <vector>
#include <memory>

class VertexBufferRenderable : public VertexBufferBase
{
public:
    VertexBufferRenderable() = default;
    void onRender() override;

    template<typename T> void makeBuffer(
        const std::vector<T>& vertices,
        unsigned int stride,
        GLenum bufferType);
};

#include "VertexBufferRenderable.hpp"