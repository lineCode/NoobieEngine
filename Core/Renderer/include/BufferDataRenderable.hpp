#pragma once

template<typename T> void BufferDataRenderable::makeBuffer(
    const std::vector<T>& vertices,
    unsigned int elementsPerComponent,
    GLenum bufferType)
{
    m_components = static_cast<unsigned int>(vertices.size());
    m_elementsPerComponent = elementsPerComponent;
    m_BufferType = bufferType;
    GLuint vertexBuffer;
    GLCall(glGenBuffers(1, &vertexBuffer))
    GLCall(glBindBuffer(bufferType, vertexBuffer))
    GLCall(glBufferData(bufferType, sizeof(T) * vertices.size(), vertices.data(), GL_STATIC_DRAW))
    m_Buffer = std::make_unique<GLResource>(vertexBuffer, [vertexBuffer]() {
        glDeleteBuffers(1, &vertexBuffer);
    });
}