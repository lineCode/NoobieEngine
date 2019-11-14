//
// Created by Rob on 2019-07-14.
//

#include "VertexBuffer.h"
#include "VertexBufferScope.h"
#include "TextureScope.h"
#include "Infrastructure/include/GLSafe.h"
#include <GL/glew.h>

void VertexBuffer::onRender()
{
    drawArrays();
}

void VertexBuffer::drawArrays()
{
    //todo, replace the following with their own renderable classes
    auto elements = components() / elementsPerComponent();
    switch (bufferMode())
    {
        case BufferMode::None:
        {
            break;
        }
        case BufferMode::NoDraw:
        {
            VertexBufferScope vertexScope(this);
            break;
        }
        case BufferMode::InstanceCopy:
        {
            VertexBufferScope vertexScope(this);
            GLCall(glDrawArraysInstanced(drawMode(), 0, elements, numberOfCopies()));
            break;
        }
        case BufferMode::Texture:
        {
            TextureScope textureScope(this);
            break;
        }
        default:
            throw std::invalid_argument("Unknown BufferMode");
    }
}