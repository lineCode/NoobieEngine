//
// Created by Rob on 2019-08-15.
//

#include "VertexBufferScope.h"

VertexBufferScope::VertexBufferScope(const VertexBuffer * vertexBuffer) :
    m_VertexBuffer(vertexBuffer)
{
    GLCall(glBindBuffer(vertexBuffer->bufferType(), vertexBuffer->handle()));
    GLCall(glVertexAttribPointer(
        vertexBuffer->attributeIndex(),
        vertexBuffer->stride(),                  // num components per vertex
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    ));
    GLCall(glEnableVertexAttribArray(vertexBuffer->attributeIndex()))
}

VertexBufferScope::~VertexBufferScope()
{
    checkBuffer();
    GLCall(glDisableVertexAttribArray(m_VertexBuffer->attributeIndex()));
}

void VertexBufferScope::checkBuffer()
{
    if (
        m_VertexBuffer->bufferMode() == BufferMode::SingleCopy &&
        m_VertexBuffer->numberOfCopies() != 1)
    {
        throw std::invalid_argument("SingleCopy mode number of copies must be 1");
    }
    else if(
        m_VertexBuffer->bufferMode() == BufferMode::InstanceCopy &&
        m_VertexBuffer->numberOfCopies() == 0)
    {
        throw std::invalid_argument("InstanceCopy mode number of copies must be greater than 0");
    }
}
