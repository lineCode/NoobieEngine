//
// Created by Rob on 2019-07-15.
//

#ifndef NOOBYENGINE_RENDERER_H
#define NOOBYENGINE_RENDERER_H

#include "VertexArray.h"
#include "Mesh.h"
#include "Camera.h"
#include "../../../Infrastructure/include/GLResource.h"
#include "../../../Interfaces/IContext.h"

class Renderer
{
public:
    explicit Renderer();

    void addRenderable(std::shared_ptr<IRenderable> );
    void render(IContext * context);
    void setCamera(std::shared_ptr<Camera> camera);
private:
    GLuint m_ProgramId;
    std::vector<std::shared_ptr<IRenderable>> m_OrderedRenderables;
    std::shared_ptr<Camera> m_Camera;
};


#endif //NOOBYENGINE_RENDERER_H
