#pragma once

#include "Interfaces/IPositionalLightModel.h"
#include <glm/glm.hpp>

class PositionalLightModel : public IPositionalLightModel
{
public:
    PositionalLightModel(glm::vec3 location, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular);
    glm::vec3 location() override;
    glm::vec3 ambient() override;
    glm::vec3 diffuse() override;
    glm::vec3 specular() override;
private:
    glm::vec3 m_location;
    glm::vec3 m_ambient;
    glm::vec3 m_diffuse;
    glm::vec3 m_specular;
};