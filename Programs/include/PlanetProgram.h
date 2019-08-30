//
// Created by Rob on 2019-08-22.
//

#ifndef NOOBYENGINE_PLANETPROGRAM_H
#define NOOBYENGINE_PLANETPROGRAM_H

#include "Core/include/DrawableObject.h"
#include "Programs/include/BaseProgram.h"

class PlanetProgram : public BaseProgram
{
public:
    PlanetProgram(std::shared_ptr<Camera> camera);
    void addObject(std::shared_ptr<DrawableObject> object);
    void onRender() override;
private:
    std::vector<std::shared_ptr<DrawableObject>> m_Objects;
};


#endif //NOOBYENGINE_PLANETPROGRAM_H
