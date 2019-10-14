//
// Created by Rob on 2019-07-21.
//

#include "Camera.h"

Camera::Camera(glm::vec3 location, float fov, float aspect, float nearPlane, float farPlane):
    m_Location(location), m_Fov(fov), m_Aspect(aspect), m_NearPlane(nearPlane), m_FarPlane(farPlane)
{
}

glm::vec3 Camera::location() const
{
    return m_Location;
}

glm::mat4 Camera::perspectiveMatrix() const
{
    return glm::perspective(m_Fov, m_Aspect, m_NearPlane, m_FarPlane);
}

glm::mat4 Camera::viewMatrix() const
{
    return glm::translate(glm::mat4(1.0f), m_Location);
}

void Camera::setLocation(glm::vec3 location)
{
    m_Location = location;
}

void Camera::setUniform(std::string uniform)
{
    m_uniform = uniform;
}