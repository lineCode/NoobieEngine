//
// Created by Rob on 2019-07-14.
//

#include "VertexArray.h"

VertexArray::VertexArray()
{
    m_ArrayBuffer = makeArrayBuffer();
}

std::unique_ptr<GLResource> VertexArray::makeArrayBuffer()
{
    GLuint vertexArrayId;
    GLCall(glGenVertexArrays(1, &vertexArrayId));
    GLCall(glBindVertexArray(vertexArrayId));
    return std::make_unique<GLResource>(vertexArrayId, [vertexArrayId]()
    {
        glDeleteVertexArrays(1, &vertexArrayId);
    });
}

GLuint VertexArray::handle() const
{
    return m_ArrayBuffer->resourceId();
}

void VertexArray::onRender()
{
    for(auto & vertexBuffer : m_VertexBuffer)
    {
        vertexBuffer->onRender();
    }
}
