//
// Created by Rob on 2019-07-14.
//

#include "VertexArray.h"
#include "VertexBufferScope.h"

std::atomic<unsigned int> VertexArray::m_Atrib {0};

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

GLuint VertexArray::handle()
{
    return m_ArrayBuffer->resourceId();
}

void VertexArray::onRender()
{
    for(auto & vertexBuffer : m_VertexBuffer)
    {
        VertexBufferScope vertexScope(vertexBuffer.get());
        drawArrays(vertexBuffer.get());
    }
}

void VertexArray::drawArrays(VertexBuffer * vertexBuffer)
{
    auto elements = vertexBuffer->count() / vertexBuffer->stride();
    switch (vertexBuffer->bufferMode())
    {
        case BufferMode::InstanceCopy:
            GLCall(glDrawArraysInstanced(vertexBuffer->drawMode(), 0, elements, vertexBuffer->numberOfCopies()));
            break;
        case BufferMode::SingleCopy:
            GLCall(glDrawArrays(vertexBuffer->drawMode(), 0, elements));
            break;
        default:
            throw std::invalid_argument("Unknown BufferMode");
    }

}