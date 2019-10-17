//
// Created by Rob on 2019-07-24.
//

#ifndef NOOBYENGINE_VERTEXARRAY_HPP
#define NOOBYENGINE_VERTEXARRAY_HPP

template<typename T> IRenderable * VertexArray::addBuffer(
    const T & buffer,
    unsigned int stride,
    GLuint bufferType,
    GLuint drawMode)
{
    m_VertexBuffer.emplace_back(std::make_unique<VertexBufferRenderable>());
    auto vbo = static_cast<VertexBufferRenderable*>(m_VertexBuffer.back().get());
    vbo->makeBuffer(buffer, stride, bufferType);
    vbo->setDrawMode(drawMode);
    vbo->setNumberOfCopies(1);
    return vbo;
}

template<typename T> IRenderable* VertexArray::addTexture(
    std::unique_ptr<GLResource> loadedTexture, 
    const std::vector<T>& textureCoordinates, 
    unsigned int stride, GLenum bufferType)
{
    auto vbo = std::make_unique<VertexBuffer>();
    vbo->makeTexture(std::move(loadedTexture), textureCoordinates, stride, bufferType);
    m_VertexBuffer.push_front(std::move(vbo));
    return m_VertexBuffer.front().get();
}

template<typename T> IRenderable * VertexArray::addBuffer(
    const T & buffer,
    unsigned int stride,
    GLuint bufferType,
    GLuint drawMode,
    unsigned int numCopies)
{
    return addBuffer(buffer, stride, bufferType, drawMode, 1, BufferMode::InstanceCopy);
}

template<typename T> IRenderable * VertexArray::addBuffer(
    const T& buffer,
    unsigned int stride,
    GLuint bufferType,
    GLuint drawMode,
    unsigned int numCopies,
    BufferMode bufferMode)
{
    auto vbo = std::make_unique<VertexBuffer>();
    vbo->makeBuffer(buffer, stride, bufferType, bufferMode);
    vbo->setDrawMode(drawMode);
    vbo->setNumberOfCopies(numCopies);
    m_VertexBuffer.push_back(std::move(vbo));
    return m_VertexBuffer.back().get();
}

#endif //NOOBYENGINE_VERTEXARRAY_HPP
