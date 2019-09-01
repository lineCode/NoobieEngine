//
// Created by Rob on 2019-07-24.
//

#ifndef NOOBYENGINE_VERTEXBUFFER_HPP
#define NOOBYENGINE_VERTEXBUFFER_HPP

#include "VertexBuffer.h"

template<typename T> void VertexBuffer::makeBuffer(
    const std::vector<T> & vertices,
    unsigned int stride,
    GLenum bufferType)
{
    makeBuffer(vertices, stride, bufferType, BufferMode::SingleCopy);
}

template<typename T> void VertexBuffer::makeTexture(
    const std::vector<T> & textureCoordinates,
    unsigned int stride,
    GLenum bufferType)
{
    makeBuffer(textureCoordinates, stride, bufferType, BufferMode::Texture);
}

template<typename T> void VertexBuffer::makeBuffer(
    const std::vector<T> & vertices,
    unsigned int stride,
    GLenum bufferType,
    BufferMode bufferMode)
{
    m_Count = static_cast<unsigned int>(vertices.size());
    m_Stride = stride;
    m_BufferMode = bufferMode;
    GLuint vertexBuffer;
    GLCall(glGenBuffers(1, &vertexBuffer))
    GLCall(glBindBuffer(bufferType, vertexBuffer))
    GLCall(glBufferData(bufferType, sizeof(T) * vertices.size(), vertices.data(), GL_STATIC_DRAW))
    m_Buffer = std::make_unique<GLResource>(vertexBuffer, [vertexBuffer]()
    {
        glDeleteBuffers(1, &vertexBuffer);
    });
}

#endif //NOOBYENGINE_VERTEXBUFFER_HPP
