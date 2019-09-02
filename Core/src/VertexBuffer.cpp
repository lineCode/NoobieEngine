//
// Created by Rob on 2019-07-14.
//

#include "VertexBuffer.h"
#include "VertexBufferScope.h"
#include "TextureScope.h"
#include <GL/glew.h>

VertexBuffer::VertexBuffer()
    :m_DrawMode(GL_TRIANGLES)
{
    m_NumCopies = 1;
    m_BufferMode = BufferMode::SingleCopy;
}

GLuint VertexBuffer::handle()
{
    return m_Buffer->resourceId();
}

unsigned int VertexBuffer::count()
{
    return m_Count;
}

GLuint VertexBuffer::stride()
{
    return m_Stride;
}

GLuint VertexBuffer::drawMode()
{
    return m_DrawMode;
}

BufferMode VertexBuffer::bufferMode()
{
    return m_BufferMode;
}

void VertexBuffer::setNumberOfCopies(unsigned int numCopies)
{
    m_NumCopies = numCopies;
}

unsigned int VertexBuffer::numberOfCopies()
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

GLuint VertexBuffer::attributeIndex()
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

GLenum VertexBuffer::activeTextureUnit()
{
    return m_ActiveTextureUnit;
}

void VertexBuffer::setActiveTextureUnit(GLuint textureUnit)
{
    m_ActiveTextureUnit = textureUnit;
}
