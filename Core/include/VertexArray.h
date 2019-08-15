//
// Created by Rob on 2019-07-14.
//

#ifndef NOOBYENGINE_VERTEXTARRAY_H
#define NOOBYENGINE_VERTEXTARRAY_H

#include "VertexBufferMode.h"
#include "VertexBuffer.h"
#include "../Interfaces/IRenderable.h"
#include "../Infrastructure/GLSafe.h"
#include <atomic>

class VertexArray : IRenderable
{
public:
    VertexArray();
    GLuint handle();
public:
    template<typename T> void addBuffer(
        const T & buffer,
        unsigned int stride,
        GLuint bufferType,
        GLuint drawMode);
    template<typename T> void addBuffer(
        const T & buffer,
        unsigned int stride,
        GLuint bufferType,
        GLuint drawMode,
        unsigned int numCopies);
    void onRender() override;
private:
    void drawArrays(VertexBuffer * vertexBuffer);
    std::unique_ptr<GLResource> makeArrayBuffer();
private:
    std::vector<std::unique_ptr<VertexBuffer>> m_VertexBuffer;
    std::unique_ptr<GLResource> m_ArrayBuffer;
    static std::atomic<unsigned int> m_Atrib;
};

#include "VertexArray.hpp"


#endif //NOOBYENGINE_VERTEXTARRAY_H
