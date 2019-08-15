//
// Created by Rob on 2019-08-15.
//

#ifndef NOOBYENGINE_VERTEXBUFFERSCOPE_H
#define NOOBYENGINE_VERTEXBUFFERSCOPE_H

#include "VertexBufferMode.h"
#include "VertexBuffer.h"

class VertexBufferScope
{
public:
    VertexBufferScope(VertexBuffer * vertexBuffer);
    void checkBuffer();
    ~VertexBufferScope();
private:
    VertexBuffer * m_VertexBuffer;
};


#endif //NOOBYENGINE_VERTEXBUFFERSCOPE_H
