#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
    Camera() = delete;
    explicit Camera(glm::vec3 location, float fov, float aspect, float nearPlane, float farPlane);
    glm::vec3 location() const;
    void setLocation(glm::vec3 location);
    glm::mat4 perspectiveMatrix() const;
    glm::mat4 viewMatrix() const;
    void setUniform(std::string uniform);
private:
    glm::vec3 m_Location;
    float m_Aspect;
    float m_Fov;
    float m_NearPlane;
    float m_FarPlane;
    std::string m_uniform;
};

#endif // !CAMERA_H