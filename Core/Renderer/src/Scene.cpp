//
// Created by Rob on 10/9/19.
//

#include <memory>
#include "Scene.h"

Scene::Scene(float aspect)
{
    m_camera = std::make_unique<Camera>(
        glm::vec3{ 0.0f, 0.0f, -10.0f }, //location
        glm::radians<float>(59.0f), //field of view
              aspect, //aspect ratio
        0.1f, //near plane
        1000.0f); //far plane
}

void Scene::addRenderable(std::shared_ptr<IRenderable> renderableItem)
{
    m_OrderedRenderables.push_back(renderableItem);
}

void Scene::onRender()
{
    for(auto renderableObject : m_OrderedRenderables)
    {
        renderableObject->onRender();
    }
}
