//
// Created by Rob on 2019-07-21.
//

#include "Camera.h"

Camera::Camera(glm::vec3 location):
    m_Location(location)
{
}

glm::vec3 Camera::location()
{
    return m_Location;
}
