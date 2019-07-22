//
// Created by Rob on 2019-07-14.
//

#ifndef NOOBYENGINE_VERTEXTARRAY_H
#define NOOBYENGINE_VERTEXTARRAY_H

#include "VertexBuffer.h"
#include "Interfaces/IRenderable.h"

class VertexArray : IRenderable
{
public:
    VertexArray();
    GLuint handle();
public:
    template<typename T> void addBuffer(const T & buffer, GLuint bufferType);
    void onRender() override;
private:
    std::unique_ptr<GLResource> makeArrayBuffer();
private:
    std::unique_ptr<GLResource> m_ArrayBuffer;
    std::vector<std::unique_ptr<VertexBuffer>> m_VertexBuffer;
    static std::atomic<unsigned int> m_Atrib;
};


#endif //NOOBYENGINE_VERTEXTARRAY_H
