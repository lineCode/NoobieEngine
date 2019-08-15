//
// Created by Rob on 2019-08-15.
//

#include "VertexBufferScope.h"

VertexBufferScope::VertexBufferScope(VertexBuffer * vertexBuffer)
:m_VertexBuffer(vertexBuffer)
{
    GLCall(glEnableVertexAttribArray(vertexBuffer->attributeIndex()));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer->handle()));
    GLCall(glVertexAttribPointer(
        vertexBuffer->attributeIndex(),
        vertexBuffer->stride(),                  // num components per vertex
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    ));
}

VertexBufferScope::~VertexBufferScope()
{
    GLCall(glDisableVertexAttribArray(m_VertexBuffer->attributeIndex()));
}
