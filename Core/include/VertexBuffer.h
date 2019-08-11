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
    VertexBuffer();
    unsigned int count();
    GLuint attributeIndex();
    GLuint handle();
    unsigned stride();
public:
    template<typename T> void makeBuffer(
        const std::vector<T> & vertices,
        unsigned int stride,
        GLuint bufferType,
        GLuint attributeIndex,
        GLuint drawMode);

    GLuint drawMode();
private:
    std::unique_ptr<GLResource> m_Buffer;
    GLuint m_AttributeIndex;
    unsigned int m_Count;
    unsigned int m_Stride;
    GLuint m_DrawMode;
};

#include "VertexBuffer.hpp"

#endif //NOOBYENGINE_VERTEXBUFFER_H
