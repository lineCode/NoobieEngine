//
// Created by Rob on 2019-07-14.
//

#ifndef NOOBYENGINE_VERTEXBUFFER_H
#define NOOBYENGINE_VERTEXBUFFER_H

#include "Core/GLResource.h"
#include <glm/glm.hpp>
#include <vector>

class VertexBuffer {
public:
    VertexBuffer(std::vector<glm::vec3> vertices);
    GLuint handle();
private:
    std::unique_ptr<GLResource> makeBuffer(const std::vector<glm::vec3> vertices);
private:
    std::unique_ptr<GLResource> m_Buffer;
};


#endif //NOOBYENGINE_VERTEXBUFFER_H
