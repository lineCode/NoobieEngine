
#include "PositionalLightModel.h"

PositionalLightModel::PositionalLightModel(glm::vec3 location, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular)
    :m_location(location), m_ambient(ambient), m_diffuse(diffuse), m_specular(specular)
{
}

glm::vec3 PositionalLightModel::location()
{
    return m_location;
}

glm::vec3 PositionalLightModel::ambient()
{
    return m_ambient;
}

glm::vec3 PositionalLightModel::diffuse()
{
    return m_diffuse;
}

glm::vec3 PositionalLightModel::specular()
{
    return m_specular;
}