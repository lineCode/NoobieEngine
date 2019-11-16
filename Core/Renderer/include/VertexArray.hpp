//
// Created by Rob on 2019-07-24.
//

#ifndef NOOBYENGINE_VERTEXARRAY_HPP
#define NOOBYENGINE_VERTEXARRAY_HPP

template<typename T> IRenderable * VertexArray::addBuffer(
    const T & buffer,
    unsigned int elementsPerComponent,
    GLuint bufferType,
    GLuint primitiveDrawMode)
{
    m_VertexBuffer.emplace_back(std::make_unique<VertexBufferRenderable>());
    auto vbo = static_cast<VertexBufferRenderable*>(m_VertexBuffer.back().get());
    vbo->makeBuffer(buffer, elementsPerComponent, bufferType);
    vbo->setPrimitiveDrawMode(primitiveDrawMode);
    vbo->setNumberOfCopies(1);
    return vbo;
}

template<typename T> IRenderable* VertexArray::addBufferData(
    const T& buffer,
    unsigned int elementsPerComponent,
    unsigned int strideToNextComponent,
    unsigned int bytesToNextElement,
    GLuint bufferType,
    unsigned int numberOfCopies)
{
    auto vbo = std::make_unique<BufferDataRenderable>();
    vbo->makeBuffer(buffer, elementsPerComponent, bufferType);
    vbo->setStrideToNextComponent(strideToNextComponent);
    vbo->setBytesToNextComponent(bytesToNextElement);
    vbo->setNumberOfCopies(numberOfCopies);
    m_VertexBuffer.push_front(std::move(vbo));
    return m_VertexBuffer.front().get();
}

template<typename T> IRenderable* VertexArray::addBufferIndices(
    const T& buffer,
    unsigned int elementsPerComponent,
    unsigned int strideToNextComponent,
    GLuint bufferType,
    GLuint primitiveDrawMode)
{
    auto vbo = std::make_unique<BufferIndexRenderable>();
    vbo->makeBuffer(buffer, elementsPerComponent, bufferType);
    vbo->setBytesToNextComponent(0);
    vbo->setStrideToNextComponent(strideToNextComponent);
    vbo->setPrimitiveDrawMode(primitiveDrawMode);
    m_VertexBuffer.push_back(std::move(vbo));
    return m_VertexBuffer.back().get();
}

template<typename T> IRenderable* VertexArray::addTexture(
    std::unique_ptr<GLResource> loadedTexture, 
    const std::vector<T>& textureCoordinates, 
    unsigned int elementsPerComponent, GLenum bufferType)
{
    auto vbo = std::make_unique<VertexBuffer>();
    vbo->makeTexture(std::move(loadedTexture), textureCoordinates, elementsPerComponent, bufferType);
    m_VertexBuffer.push_front(std::move(vbo));
    return m_VertexBuffer.front().get();
}

template<typename T> IRenderable * VertexArray::addBuffer(
    const T & buffer,
    unsigned int elementsPerComponent,
    GLuint bufferType,
    GLuint primitiveDrawMode,
    unsigned int numCopies)
{
    return addBuffer(buffer, elementsPerComponent, bufferType, primitiveDrawMode, 1, BufferMode::InstanceCopy);
}

template<typename T> IRenderable * VertexArray::addBuffer(
    const T& buffer,
    unsigned int elementsPerComponent,
    GLuint bufferType,
    GLuint primitiveDrawMode,
    unsigned int numCopies,
    BufferMode bufferMode)
{
    auto vbo = std::make_unique<VertexBuffer>();
    vbo->makeBuffer(buffer, elementsPerComponent, bufferType, bufferMode);
    vbo->setPrimitiveDrawMode(primitiveDrawMode);
    vbo->setNumberOfCopies(numCopies);
    m_VertexBuffer.push_back(std::move(vbo));
    return m_VertexBuffer.back().get();
}

#endif //NOOBYENGINE_VERTEXARRAY_HPP
