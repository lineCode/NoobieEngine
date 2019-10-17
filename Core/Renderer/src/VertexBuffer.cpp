//
// Created by Rob on 2019-07-14.
//

#include "VertexBuffer.h"
#include "VertexBufferScope.h"
#include "TextureScope.h"
#include "Infrastructure/include/GLSafe.h"
#include <GL/glew.h>

VertexBuffer::VertexBuffer()
{
    m_DrawMode = GL_TRIANGLES;
    m_ActiveTextureUnit = GL_TEXTURE0;
    m_Count = 0;
    m_Stride = 0;
    m_attributeIndex = 0;
    m_NumCopies = 1;
    m_BufferType = GL_ARRAY_BUFFER;
    m_BufferMode = BufferMode::SingleCopy;
}

void VertexBuffer::onRender()
{
    drawArrays();
}

void VertexBuffer::drawArrays()
{
    auto elements = count() / stride();
    switch (bufferMode())
    {
        case BufferMode::None:
        {
            break;
        }
        case BufferMode::NoDraw:
        {
            VertexBufferScope vertexScope(this);
            break;
        }
        case BufferMode::InstanceCopy:
        {
            VertexBufferScope vertexScope(this);
            GLCall(glDrawArraysInstanced(drawMode(), 0, elements, numberOfCopies()));
            break;
        }
        case BufferMode::Texture:
        {
            TextureScope textureScope(this);
            break;
        }
        default:
            throw std::invalid_argument("Unknown BufferMode");
    }
}