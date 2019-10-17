//
// Created by Rob on 2019-08-31.
//

#include "TextureScope.h"
#include "Infrastructure/include/GLSafe.h"

TextureScope::TextureScope(VertexBuffer * vertexBuffer)
{
    ////texture coordinates
    //GLCall(glBindBuffer(vertexBuffer->bufferType(), vertexBuffer->handle()));
    //GLCall(glVertexAttribPointer(
    //    vertexBuffer->attributeIndex(),
    //    vertexBuffer->stride(),                  // num components per vertex
    //    GL_FLOAT,           // type
    //    GL_FALSE,           // normalized?
    //    0,                  // stride
    //    (void*)0            // array buffer offset
    //));

    ////texture object
    //GLCall(glEnableVertexAttribArray(vertexBuffer->attributeIndex()))
    GLCall(glActiveTexture(vertexBuffer->activeTextureUnit()))
    GLCall(glBindTexture(GL_TEXTURE_2D, vertexBuffer->textureHandle()))
    GLCall(glUniform1i(vertexBuffer->textureUniformLocation(), 0))
}