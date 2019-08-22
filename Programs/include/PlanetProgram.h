//
// Created by Rob on 2019-08-22.
//

#ifndef NOOBYENGINE_PLANETPROGRAM_H
#define NOOBYENGINE_PLANETPROGRAM_H

#include "Interfaces/IRenderable.h"
#include "Infrastructure/GLResource.h"
#include "Core/include/Camera.h"
#include "Core/include/DrawableObject.h"

class PlanetProgram : public IRenderable
{
public:
    PlanetProgram(std::unique_ptr<GLResource> program, std::shared_ptr<Camera> camera);
    void addObject(std::shared_ptr<DrawableObject> object);
    void onRender() override;
private:
    std::unique_ptr<GLResource> m_Program;
    std::shared_ptr<Camera> m_Camera;
    std::vector<std::shared_ptr<DrawableObject>> m_Objects;
};


#endif //NOOBYENGINE_PLANETPROGRAM_H
