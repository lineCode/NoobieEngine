//
// Created by Rob on 2019-07-14.
//

#include "VertexBuffer.h"
#include "GLSafe.h"
#include <GL/glew.h>

VertexBuffer::VertexBuffer(std::vector<glm::vec3> vertices) {
    m_Buffer = makeBuffer(vertices);
}

std::unique_ptr<GLResource> VertexBuffer::makeBuffer(const std::vector<glm::vec3> vertices) {
    GLuint vertexbuffer;
    GLCall(glGenBuffers(1, &vertexbuffer));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer));
    GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW));
    return std::make_unique<GLResource>(vertexbuffer, [vertexbuffer]()
    {
        glDeleteBuffers(1, &vertexbuffer);
    });
}

GLuint VertexBuffer::handle()
{
    return m_Buffer->resourceId();
}
