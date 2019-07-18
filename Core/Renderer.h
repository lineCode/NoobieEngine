//
// Created by Rob on 2019-07-15.
//

#ifndef NOOBYENGINE_RENDERER_H
#define NOOBYENGINE_RENDERER_H

#include "GLResource.h"
#include "VertexArray.h"
#include "Interfaces/IContext.h"

class Renderer
{
public:
    Renderer(
        std::unique_ptr<GLResource> programId,
        std::unique_ptr<VertexArray> vertexArray);
    void render(IContext * context);
private:
    std::unique_ptr<GLResource> m_ProgramId;
    std::unique_ptr<VertexArray> m_VertexArray;
};


#endif //NOOBYENGINE_RENDERER_H
