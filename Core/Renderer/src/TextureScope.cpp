//
// Created by Rob on 2019-08-31.
//

#include "TextureScope.h"
#include "Infrastructure/include/GLSafe.h"

TextureScope::TextureScope(VertexBuffer * vertexBuffer)
{
    GLCall(glActiveTexture(vertexBuffer->activeTextureUnit()))
    GLCall(glBindTexture(GL_TEXTURE_2D, vertexBuffer->textureHandle()))
    GLCall(glUniform1i(vertexBuffer->textureUniformLocation(), 0))
}