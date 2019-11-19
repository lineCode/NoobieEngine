//
// Created by Rob on 10/9/19.
//

#ifndef NOOBYENGINE_SCENE_H
#define NOOBYENGINE_SCENE_H

#include "Camera.h"
#include "../../../Interfaces/IRenderableObject.h"
#include "../../../Interfaces/IPositionalLightModel.h"
#include <vector>

class Scene : public IRenderable
{
public:
    explicit Scene(float aspect);
    void addRenderable(std::shared_ptr<IRenderableObject> renderable);
    void setWorldCameraLocation(glm::vec3 location);
    void addPositionalLightModel(std::unique_ptr<IRenderableObject> lightModel);
    void onRender() override;
private:
    std::unique_ptr<Camera> m_camera;
    std::vector<std::shared_ptr<IRenderableObject>> m_OrderedRenderables;
    std::vector<std::unique_ptr<IRenderableObject>> m_positionalLightModels;
};


#endif //NOOBYENGINE_SCENE_H
