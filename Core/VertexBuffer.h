//
// Created by Rob on 2019-07-14.
//

#ifndef NOOBYENGINE_VERTEXBUFFER_H
#define NOOBYENGINE_VERTEXBUFFER_H

#include "Core/GLResource.h"
#include "Interfaces/IRenderable.h"
#include <glm/glm.hpp>
#include <vector>

class VertexBuffer{
public:
    VertexBuffer();
    unsigned int count();
    GLuint attributeIndex();
    GLuint handle();
    template<typename T> std::unique_ptr<GLResource> makeBuffer(const std::vector<T> & vertices, GLuint bufferType, GLuint attributeIndex);
private:
    std::unique_ptr<GLResource> m_Buffer;
    GLuint m_AttributeIndex;
    unsigned int m_Count;
};


#endif //NOOBYENGINE_VERTEXBUFFER_H
