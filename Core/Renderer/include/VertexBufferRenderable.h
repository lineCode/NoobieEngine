#pragma once

#include "VertexBufferBase.h"
#include "../../Infrastructure/include/GLResource.h"
#include <GL/glew.h>
#include <vector>
#include <memory>

class VertexBufferRenderable : public VertexBufferBase
{
public:
    VertexBufferRenderable();
    void onRender() override;

    template<typename T> void makeBuffer(
        const std::vector<T>& vertices,
        unsigned int stride,
        GLenum bufferType);

private:
    GLuint m_attributeIndex;
    GLuint m_Stride;
    GLuint m_DrawMode;
    GLenum m_BufferType;
    unsigned int m_Count;
    unsigned int m_NumCopies;
    std::unique_ptr<GLResource> m_Buffer;
};

#include "VertexBufferRenderable.hpp"