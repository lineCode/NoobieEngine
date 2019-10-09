//
// Created by Rob on 10/9/19.
//

#ifndef NOOBYENGINE_SCENE_H
#define NOOBYENGINE_SCENE_H

#include "Camera.h"
#include <vector>
#include "../../../Interfaces/IRenderable.h"

class Scene : public IRenderable
{
public:
    explicit Scene(float aspect);
    void addRenderable(std::shared_ptr<IRenderable> renderable);
    void onRender() override;
private:
    std::unique_ptr<Camera> m_camera;
    std::vector<std::shared_ptr<IRenderable>> m_OrderedRenderables;
};


#endif //NOOBYENGINE_SCENE_H
