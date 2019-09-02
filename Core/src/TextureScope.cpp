//
// Created by Rob on 2019-08-31.
//

#include "TextureScope.h"

TextureScope::TextureScope(VertexBuffer * vertexBuffer)
{
    GLCall(glActiveTexture(vertexBuffer->activeTextureUnit()))
    GLCall(glBindTexture(GL_TEXTURE_2D, vertexBuffer->handle()))
}