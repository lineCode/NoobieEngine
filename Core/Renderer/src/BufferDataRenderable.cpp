#include "BufferDataRenderable.h"

void BufferDataRenderable::onRender()
{
    GLCall(glBindBuffer(VertexBufferBase::bufferType(), VertexBufferBase::handle()))
    GLCall(glEnableVertexAttribArray(VertexBufferBase::attributeIndex()))
    GLCall(glVertexAttribPointer(
        VertexBufferBase::attributeIndex(),
        VertexBufferBase::elementsPerComponent(),                   // num components per vertex
        GL_FLOAT,                                                   // type
        GL_FALSE,                                                   // normalized?
        VertexBufferBase::strideToNextComponent(),                                                          // stride
        (void*)VertexBufferBase::bytesToNextComponent()             // array buffer offset
    ))
}