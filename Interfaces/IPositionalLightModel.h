#pragma once

#include <glm/glm.hpp>

class IPositionalLightModel
{
public:
    virtual glm::vec3 location() = 0;
    virtual glm::vec3 ambient() = 0;
    virtual glm::vec3 diffuse() = 0;
    virtual glm::vec3 specular() = 0;
};