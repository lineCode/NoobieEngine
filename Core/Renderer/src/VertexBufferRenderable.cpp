#include "VertexBufferRenderable.h"
#include "VertexBufferScope.h"
#include "Infrastructure/include/GLSafe.h"

VertexBufferRenderable::VertexBufferRenderable()
{
    m_DrawMode = GL_TRIANGLES;
    m_Count = 0;
    m_Stride = 0;
    m_attributeIndex = 0;
    m_NumCopies = 1;
    m_BufferType = GL_ARRAY_BUFFER;
}


void VertexBufferRenderable::onRender()
{
    auto elements = count() / stride();
    GLCall(glBindBuffer(bufferType(), handle()))
    GLCall(glVertexAttribPointer(
        attributeIndex(),
        stride(),                  // num components per vertex
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        nullptr            // array buffer offset
        ))
    GLCall(glEnableVertexAttribArray(attributeIndex()))
    GLCall(glDrawArrays(drawMode(), 0, elements));
}