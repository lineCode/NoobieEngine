//
// Created by Rob on 2019-07-15.
//

#ifndef NOOBYENGINE_RENDERER_H
#define NOOBYENGINE_RENDERER_H

#include "VertexArray.h"
#include "Mesh.h"
#include "Scene.h"
#include "Interfaces/IContext.h"
#include "Infrastructure/include/GLResource.h"

class Renderer
{
public:
    explicit Renderer();
    void render(IContext * context);
    void addScene(std::shared_ptr<Scene> scene);
private:
    std::vector<std::shared_ptr<Scene>> m_scenes;
};


#endif //NOOBYENGINE_RENDERER_H
