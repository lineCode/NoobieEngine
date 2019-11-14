//
// Created by Rob on 2019-07-14.
//

#ifndef NOOBYENGINE_VERTEXTARRAY_H
#define NOOBYENGINE_VERTEXTARRAY_H

#include "BufferMode.h"
#include "VertexBuffer.h"
#include "VertexBufferRenderable.h"
#include "../../../Interfaces/IRenderable.h"
#include "../../Infrastructure/include/GLSafe.h"
#include <list>

class VertexArray : IRenderable
{
public:
    VertexArray();
    GLuint handle() const;
public:
    template<typename T> IRenderable * addBuffer(
        const T & buffer,
        unsigned int elementsPerComponent,
        GLuint bufferType,
        GLuint drawMode);
    template<typename T> IRenderable * addBuffer(
        const T & buffer,
        unsigned int elementsPerComponent,
        GLuint bufferType,
        GLuint drawMode,
        unsigned int numCopies);
    template<typename T> IRenderable * addBuffer(
        const T& buffer,
        unsigned int elementsPerComponent,
        GLuint bufferType,
        GLuint drawMode,
        unsigned int numCopies,
        BufferMode bufferMode);
    template<typename T> IRenderable * addTexture(
        std::unique_ptr<GLResource> loadedTexture,
        const std::vector<T>& textureCoordinates,
        unsigned int elementsPerComponent,
        GLenum bufferType);

    void onRender() override;
private:
    std::unique_ptr<GLResource> makeArrayBuffer();
private:
    std::list<std::unique_ptr<IRenderable>> m_VertexBuffer;
    std::unique_ptr<GLResource> m_ArrayBuffer;
};

#include "VertexArray.hpp"


#endif //NOOBYENGINE_VERTEXTARRAY_H
