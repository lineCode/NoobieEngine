//
// Created by Rob on 2019-07-14.
//

#include "VertexBuffer.h"
#include "VertexBufferScope.h"
#include "TextureScope.h"
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

GLuint VertexBuffer::handle() const
{
    return m_Buffer->resourceId();
}

GLuint VertexBuffer::textureHandle() const
{
    return m_LoadedTexture->resourceId();
}

unsigned int VertexBuffer::count() const
{
    return m_Count;
}

GLuint VertexBuffer::stride() const
{
    return m_Stride;
}

GLuint VertexBuffer::drawMode() const
{
    return m_DrawMode;
}

BufferMode VertexBuffer::bufferMode() const
{
    return m_BufferMode;
}

void VertexBuffer::setNumberOfCopies(unsigned int numCopies)
{
    m_NumCopies = numCopies;
}

unsigned int VertexBuffer::numberOfCopies() const
{
    return m_NumCopies;
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
        case BufferMode::InstanceCopy:
        {
            VertexBufferScope vertexScope(this);
            GLCall(glDrawArraysInstanced(drawMode(), 0, elements, numberOfCopies()));
            break;
        }
        case BufferMode::SingleCopy:
        {
            VertexBufferScope vertexScope(this);
            GLCall(glDrawArrays(drawMode(), 0, elements));
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

GLuint VertexBuffer::attributeIndex() const
{
    return m_attributeIndex;
}

void VertexBuffer::setAttributeIndex(GLuint attributeIndex)
{
    m_attributeIndex = attributeIndex;
}

void VertexBuffer::setDrawMode(GLuint drawMode)
{
    m_DrawMode = drawMode;
}

GLenum VertexBuffer::activeTextureUnit() const
{
    return m_ActiveTextureUnit;
}

void VertexBuffer::setActiveTextureUnit(GLuint textureUnit)
{
    m_ActiveTextureUnit = textureUnit;
}

GLenum VertexBuffer::bufferType() const
{
    return m_BufferType;
}

void VertexBuffer::setBufferType(GLenum bufferType)
{
    m_BufferType = bufferType;
}
