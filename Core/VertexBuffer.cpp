//
// Created by Rob on 2019-07-14.
//

#include "VertexBuffer.h"
#include "GLSafe.h"
#include <GL/glew.h>

VertexBuffer::VertexBuffer()
{
}

template<typename T> std::unique_ptr<GLResource> VertexBuffer::makeBuffer(const std::vector<T> & vertices, GLuint bufferType, GLuint attributeIndex) {
    m_AttributeIndex = attributeIndex;
    m_Count = static_cast<unsigned int>(vertices.size());
    GLuint vertexbuffer;
    GLCall(glGenBuffers(1, &vertexbuffer))
    GLCall(glBindBuffer(bufferType, vertexbuffer))
    GLCall(glBufferData(bufferType, sizeof(T) * vertices.size(), &vertices[0], GL_STATIC_DRAW))
    return std::make_unique<GLResource>(vertexbuffer, [vertexbuffer]()
    {
        glDeleteBuffers(1, &vertexbuffer);
    });
}

GLuint VertexBuffer::handle()
{
    return m_Buffer->resourceId();
}

GLuint VertexBuffer::attributeIndex()
{
    return m_AttributeIndex;
}

unsigned int VertexBuffer::count()
{
    return m_Count;
}
