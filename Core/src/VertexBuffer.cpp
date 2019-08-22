//
// Created by Rob on 2019-07-14.
//

#include "VertexBuffer.h"
#include "VertexBufferScope.h"
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
    VertexBufferScope vertexScope(this);
    drawArrays();
}

void VertexBuffer::drawArrays()
{
    auto elements = count() / stride();
    switch (bufferMode())
    {
        case BufferMode::InstanceCopy:
            GLCall(glDrawArraysInstanced(drawMode(), 0, elements, numberOfCopies()));
            break;
        case BufferMode::SingleCopy:
            GLCall(glDrawArrays(drawMode(), 0, elements));
            break;
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
