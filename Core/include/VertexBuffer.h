//
// Created by Rob on 2019-07-14.
//

#ifndef NOOBYENGINE_VERTEXBUFFER_H
#define NOOBYENGINE_VERTEXBUFFER_H

#include "../Infrastructure/GLResource.h"
#include "../Interfaces/IRenderable.h"
#include "../Infrastructure/GLSafe.h"
#include <glm/glm.hpp>
#include <vector>
#include <memory>

class VertexBuffer{
public:
    VertexBuffer() = default;
    unsigned int count();
    GLuint attributeIndex();
    GLuint handle();
    unsigned stride();
public:
    template<typename T> void makeBuffer(const std::vector<T> & vertices, GLuint bufferType, GLuint attributeIndex);
private:
    std::unique_ptr<GLResource> m_Buffer;
    GLuint m_AttributeIndex;
    unsigned int m_Count;
    unsigned int m_Stride;
};

#include "VertexBuffer.hpp"

#endif //NOOBYENGINE_VERTEXBUFFER_H
