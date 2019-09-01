//
// Created by Rob on 2019-08-31.
//

#include "../include/Texture.h"

Texture::Texture()
{}

void Texture::setTextureUnit(GLenum textureUnit)
{
    m_TextureUnit = textureUnit;
}

void Texture::onRender()
{
    for(const auto & texture : m_VertexBuffer)
    {
        texture->setTextureUnit(m_TextureUnit);
        onRender();
    }
}
