//
// Created by Rob on 10/9/19.
//

#include <memory>
#include "Scene.h"

Scene::Scene(float aspect)
{
    m_camera = std::make_unique<Camera>(
        glm::vec3{ 0.0f, 0.0f, -10.0f },    //location
        glm::radians<float>(59.0f),         //field of view
        aspect,                             //aspect ratio
        0.1f,                               //near plane
        1000.0f);                           //far plane
}

void Scene::addRenderable(std::shared_ptr<IRenderableObject> renderableItem)
{
    m_OrderedRenderables.push_back(renderableItem);
}

void Scene::setWorldCameraLocation(glm::vec3 location)
{
    m_camera->setLocation(location);
}

void Scene::onRender()
{
    for(auto renderableObject : m_OrderedRenderables)
    {
        renderableObject->setViewMatrix(m_camera->viewMatrix());
        renderableObject->setProjectionMatrix(m_camera->perspectiveMatrix());
        renderableObject->onRender();
    }
}

void Scene::addPositionalLightModel(std::shared_ptr<IRenderableObject> lightModel)
{
    m_positionalLightModels.push_back(std::move(lightModel));
}