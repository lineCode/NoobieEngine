//
// Created by Rob on 2019-07-14.
//

#include "VertexArray.h"
#include "GLSafe.h"

VertexArray::VertexArray(const std::vector<glm::vec3> & vertices)
{
    m_VertexBuffer = std::make_unique<VertexBuffer>(vertices);
    m_ArrayBuffer = arrayBuffer(m_VertexBuffer.get());
    m_Count = static_cast<unsigned int>(vertices.size());
}

std::unique_ptr<GLResource> VertexArray::arrayBuffer(VertexBuffer * vertexBuffer)
{
    GLuint vertexArrayId;
    GLCall(glGenVertexArrays(1, &vertexArrayId));
    GLCall(glBindVertexArray(vertexArrayId));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->handle()));
    return std::make_unique<GLResource>(vertexArrayId, [vertexArrayId]()
    {
        glDeleteVertexArrays(1, &vertexArrayId);
    });
}

GLuint VertexArray::handle()
{
    return m_ArrayBuffer->resourceId();
}

unsigned int VertexArray::count()
{
    return m_Count;
}
