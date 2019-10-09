//
// Created by Roberto on 2019-09-28.
//


#ifndef NOOBYENGINE_SPHEREPROGRAM_H
#define NOOBYENGINE_SPHEREPROGRAM_H

#include "BaseProgram.h"
#include "Core/Renderer/include/SphereObject.h"

class SphereProgram : public BaseProgram
{
public:
    SphereProgram(std::unique_ptr<GLResource> program);
    void onRender() override;
    void addObject(std::shared_ptr<SphereObject> object);
private:
    void setupVertices();
private:
    std::vector<std::shared_ptr<SphereObject>> m_Objects;
};


#endif //NOOBYENGINE_SPHEREPROGRAM_H
