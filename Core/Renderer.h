//
// Created by Rob on 2019-07-15.
//

#ifndef NOOBYENGINE_RENDERER_H
#define NOOBYENGINE_RENDERER_H

#include "GLResource.h"
#include "VertexArray.h"
#include "Mesh.h"
#include "Interfaces/IContext.h"

class Renderer
{
public:
    Renderer(GLuint program);

    void render(IContext * context, IRenderable * renderable);
private:
    GLuint m_ProgramId;
};


#endif //NOOBYENGINE_RENDERER_H
