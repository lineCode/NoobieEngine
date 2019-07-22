//
// Created by Rob on 2019-07-15.
//

#include "Renderer.h"
#include "GLSafe.h"

Renderer::Renderer(GLuint program):
m_ProgramId(program)
{
}

void Renderer::render(IContext * context, IRenderable * renderable)
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLCall(glUseProgram(m_ProgramId));

    renderable->onRender();

    GLCall(glDrawArrays(GL_TRIANGLES, 0, 3)); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);

    context->swapBuffer();
}
