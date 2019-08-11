#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera
{
public:
    Camera(glm::vec3 location);
private:
    glm::vec3 m_Location;
};

#endif // !CAMERA_H