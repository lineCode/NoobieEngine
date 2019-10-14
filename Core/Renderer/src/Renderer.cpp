//
// Created by Rob on 2019-07-15.
//

#include "Renderer.h"
#include "../../Infrastructure/include/GLSafe.h"

Renderer::Renderer()
{
}

void Renderer::render(IContext * context)
{
    GLCall(glEnable(GL_DEPTH_TEST));
    GLCall(glDepthFunc(GL_LEQUAL));
    GLCall(glClearColor(0.0, 0.0, 0.0, 1.0));
    GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

    for(auto scene : m_scenes)
    {
        scene->onRender();
    }

    context->swapBuffer();
}

void Renderer::addScene(std::shared_ptr<Scene> scene)
{
    m_scenes.push_back(scene);
}
