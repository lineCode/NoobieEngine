#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
    Camera() = delete;
    explicit Camera(glm::vec3 location, float fov, float aspect, float nearPlane, float farPlane);
    glm::vec3 location();
    glm::mat4 perspectiveMatrix();
private:
    glm::vec3 m_Location;
    float m_Aspect;
    float m_Fov;
    float m_NearPlane;
    float m_FarPlane;

};

#endif // !CAMERA_H