//
// Created by Rob on 2019-08-22.
//

#ifndef NOOBYENGINE_PLANETPROGRAM_H
#define NOOBYENGINE_PLANETPROGRAM_H

#include "Core/Primitives/include/DrawableObject.h"
#include "Programs/include/BaseProgram.h"
#include "Camera.h"

class PlanetProgram : public BaseProgram
{
public:
    PlanetProgram(std::unique_ptr<GLResource> program, std::shared_ptr<Camera> camera);
    //remove
    void addObject(std::shared_ptr<DrawableObject> object);
private:
    std::vector<std::shared_ptr<DrawableObject>> m_Objects;
    std::shared_ptr<Camera> m_Camera;
};


#endif //NOOBYENGINE_PLANETPROGRAM_H
