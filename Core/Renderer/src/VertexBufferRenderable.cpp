#include "VertexBufferRenderable.h"
#include "VertexBufferScope.h"
#include "Infrastructure/include/GLSafe.h"

VertexBufferRenderable::VertexBufferRenderable()
{
    m_DrawMode = GL_TRIANGLES;
    m_components = 0;
    m_elementsPerComponent = 0;
    m_attributeIndex = 0;
    m_NumCopies = 1;
    m_BufferType = GL_ARRAY_BUFFER;
}


void VertexBufferRenderable::onRender()
{
    auto elements = VertexBufferBase::components() / VertexBufferBase::elementsPerComponent();
    GLCall(glBindBuffer(VertexBufferBase::bufferType(), VertexBufferBase::handle()))
    GLCall(glVertexAttribPointer(
        VertexBufferBase::attributeIndex(),
        VertexBufferBase::elementsPerComponent(),                  // num components per vertex
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        nullptr            // array buffer offset
        ))
    GLCall(glEnableVertexAttribArray(VertexBufferBase::attributeIndex()))
    GLCall(glDrawArrays(VertexBufferBase::drawMode(), 0, elements));
}