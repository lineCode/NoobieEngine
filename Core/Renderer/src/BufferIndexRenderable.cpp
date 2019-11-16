#include "BufferIndexRenderable.h"

void BufferIndexRenderable::onRender()
{
    GLCall(glBindBuffer(VertexBufferBase::bufferType(), VertexBufferBase::handle()))
    GLCall(glEnableVertexAttribArray(VertexBufferBase::attributeIndex()))
    GLCall(glDrawElements(VertexBufferBase::primitiveDrawMode(), VertexBufferBase::components(), GL_UNSIGNED_INT, 0))
}