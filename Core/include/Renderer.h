//
// Created by Rob on 2019-07-15.
//

#ifndef NOOBYENGINE_RENDERER_H
#define NOOBYENGINE_RENDERER_H

#include "VertexArray.h"
#include "Mesh.h"
#include "Camera.h"
#include "../Infrastructure/GLResource.h"
#include "../Interfaces/IContext.h"

class Renderer
{
public:
    explicit Renderer(GLuint program);

    void render(IContext * context, IRenderable * renderable);
    void setCamera(std::shared_ptr<Camera> camera);
private:
    GLuint m_ProgramId;
    std::shared_ptr<Camera> m_Camera;
};


#endif //NOOBYENGINE_RENDERER_H
