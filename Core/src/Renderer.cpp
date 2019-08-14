//
// Created by Rob on 2019-07-15.
//

#include "Renderer.h"
#include "../Infrastructure/GLSafe.h"

Renderer::Renderer()
{
}

void Renderer::render(IContext * context)
{
    for(auto renderable : m_OrderedRenderables)
    {
        renderable->onRender();
    }

    context->swapBuffer();
}

void Renderer::setCamera(std::shared_ptr<Camera> camera)
{
    m_Camera = camera;
}

void Renderer::addRenderable(std::shared_ptr<IRenderable> renderableItem)
{
    m_OrderedRenderables.push_back(renderableItem);
}
