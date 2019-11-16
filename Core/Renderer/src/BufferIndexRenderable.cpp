#include "BufferIndexRenderable.h"

void BufferIndexRenderable::onRender()
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
    GLCall(glDrawElements(VertexBufferBase::drawMode(), VertexBufferBase::components(), GL_UNSIGNED_INT, 0))
}