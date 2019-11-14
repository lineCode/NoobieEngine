#include "VertexBufferRenderable.h"
#include "VertexBufferScope.h"
#include "Infrastructure/include/GLSafe.h"

void VertexBufferRenderable::onRender()
{
    auto elements = VertexBufferBase::components() / VertexBufferBase::elementsPerComponent();
    GLCall(glBindBuffer(VertexBufferBase::bufferType(), VertexBufferBase::handle()))
    GLCall(glVertexAttribPointer(
        VertexBufferBase::attributeIndex(),
        VertexBufferBase::elementsPerComponent(),                   // num components per vertex
        GL_FLOAT,                                                   // type
        GL_FALSE,                                                   // normalized?
        VertexBufferBase::strideToNextComponent(),                                                          // stride
        (void*)VertexBufferBase::bytesToNextComponent()             // array buffer offset
        ))
    GLCall(glEnableVertexAttribArray(VertexBufferBase::attributeIndex()))
    GLCall(glDrawArrays(VertexBufferBase::drawMode(), 0, elements));
}