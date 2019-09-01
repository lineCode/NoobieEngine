//
// Created by Rob on 2019-08-31.
//

#ifndef NOOBYENGINE_TEXTURE_H
#define NOOBYENGINE_TEXTURE_H

#include "VertexBuffer.h"
#include "../Interfaces/IRenderable.h"

class Texture : public IRenderable
{
public:
    Texture();
    template<typename T> void addTexture(
        const T & buffer,
        unsigned int stride,
        GLuint bufferType);
    void setTextureUnit(GLenum textureUnit);
    void onRender() override;
private:
    GLuint m_TextureUnit;
    std::vector<std::unique_ptr<VertexBuffer>> m_VertexBuffer;
};

#include "Texture.hpp"

#endif //NOOBYENGINE_TEXTURE_H
