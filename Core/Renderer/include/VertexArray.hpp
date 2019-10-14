//
// Created by Rob on 2019-07-24.
//

#ifndef NOOBYENGINE_VERTEXARRAY_HPP
#define NOOBYENGINE_VERTEXARRAY_HPP

template<typename T> VertexBuffer * VertexArray::addBuffer(
    const T & buffer,
    unsigned int stride,
    GLuint bufferType,
    GLuint drawMode)
{
    return addBuffer(buffer, stride, bufferType, drawMode, 1);
}

template<typename T> VertexBuffer * VertexArray::addTexture(
    std::unique_ptr<GLResource> loadedTexture, 
    const std::vector<T>& textureCoordinates, 
    unsigned int stride, GLenum bufferType)
{
    auto vbo = std::make_unique<VertexBuffer>();
    vbo->makeTexture(std::move(loadedTexture), textureCoordinates, stride, bufferType);
    m_VertexBuffer.push_back(std::move(vbo));
    return m_VertexBuffer.back().get();
}

template<typename T> VertexBuffer * VertexArray::addBuffer(
    const T & buffer,
    unsigned int stride,
    GLuint bufferType,
    GLuint drawMode,
    unsigned int numCopies)
{
    auto vbo = std::make_unique<VertexBuffer>();
    vbo->makeBuffer(buffer, stride, bufferType, BufferMode::InstanceCopy);
    vbo->setDrawMode(drawMode);
    vbo->setNumberOfCopies(numCopies);
    m_VertexBuffer.push_back(std::move(vbo));
    return m_VertexBuffer.back().get();
}

#endif //NOOBYENGINE_VERTEXARRAY_HPP
