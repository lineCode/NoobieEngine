//
// Created by Rob on 2019-08-31.
//

#ifndef NOOBYENGINE_TEXTURE_HPP
#define NOOBYENGINE_TEXTURE_HPP

template<typename T> void Texture::addTexture(
    const T & buffer,
    unsigned int stride,
    GLuint bufferType)
{
    auto vbo = std::make_unique<VertexBuffer>();
    vbo->makeTexture(buffer, stride, bufferType);
    m_VertexBuffer.push_back(std::move(vbo));
}

#endif //NOOBYENGINE_TEXTURE_HPP
