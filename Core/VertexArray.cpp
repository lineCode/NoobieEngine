//
// Created by Rob on 2019-07-14.
//

#include "VertexArray.h"

std::atomic<unsigned int> VertexArray::m_Atrib {0};

VertexArray::VertexArray()
{
    m_ArrayBuffer = makeArrayBuffer();
}

GLuint VertexArray::handle()
{
    return m_ArrayBuffer->resourceId();
}

void VertexArray::onRender()
{
    for(auto & vertexBuffer : m_VertexBuffer)
    {
        auto elements = vertexBuffer->count() / vertexBuffer->stride();
        glEnableVertexAttribArray(vertexBuffer->attributeIndex());
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->handle());
        glVertexAttribPointer(
            vertexBuffer->attributeIndex(),
            elements,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );
        GLCall(glDrawArrays(GL_TRIANGLES, 0, elements));
        glDisableVertexAttribArray(vertexBuffer->attributeIndex());
    }
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
