//
// Created by Rob on 2019-07-14.
//

#ifndef NOOBYENGINE_VERTEXTARRAY_H
#define NOOBYENGINE_VERTEXTARRAY_H

#include "VertexBuffer.h"

class VertexArray
{
public:
    VertexArray(const std::vector<glm::vec3> & vertices);
    GLuint handle();
    unsigned int count();
private:
    std::unique_ptr<GLResource> arrayBuffer(VertexBuffer * vertexBuffer);
private:
    unsigned int m_Count;
    std::unique_ptr<GLResource> m_ArrayBuffer;
    std::unique_ptr<VertexBuffer> m_VertexBuffer;
};


#endif //NOOBYENGINE_VERTEXTARRAY_H
