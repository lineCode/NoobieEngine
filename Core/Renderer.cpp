//
// Created by Rob on 2019-07-15.
//

#include "Renderer.h"
#include "GLSafe.h"

Renderer::Renderer(std::unique_ptr<GLResource> programId, std::unique_ptr<VertexArray> vertexArray)
{
    m_ProgramId = std::move(programId);
    m_VertexArray = std::move(vertexArray);
}

void Renderer::render(IContext * context)
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLCall(glUseProgram(m_ProgramId->resourceId()));
    GLCall(glEnableVertexAttribArray(0));
    GLCall(glVertexAttribPointer(
        0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
        m_VertexArray->count(),                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    ));

    GLCall(glDrawArrays(GL_TRIANGLES, 0, 3)); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);

    context->swapBuffer();
}
