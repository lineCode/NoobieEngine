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
    context->swapBuffer();
}
