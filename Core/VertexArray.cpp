//
// Created by Rob on 2019-07-14.
//

#include "VertexArray.h"
#include "GLSafe.h"

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

template<typename T> void VertexArray::addBuffer(const T & buffer, GLuint bufferType)
{
    auto vbo = std::make_unique<VertexBuffer>();
    vbo->makeBuffer(buffer, bufferType, m_Atrib++);
    m_VertexBuffer.push_back(std::move(vbo));
}

void VertexArray::onRender()
{
    for(auto & vertexBuffer : m_VertexBuffer)
    {
        glEnableVertexAttribArray(vertexBuffer->attributeIndex());
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->handle());
        glVertexAttribPointer(
            vertexBuffer->attributeIndex(),
            vertexBuffer->count(),                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );
    }
}
