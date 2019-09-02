//
// Created by Rob on 2019-07-14.
//

#ifndef NOOBYENGINE_VERTEXTARRAY_H
#define NOOBYENGINE_VERTEXTARRAY_H

#include "BufferMode.h"
#include "VertexBuffer.h"
#include "../Interfaces/IRenderable.h"
#include "../Infrastructure/GLSafe.h"

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
    template<typename T> void addTexture(
        std::unique_ptr<GLResource> loadedTexture,
        const std::vector<T>& textureCoordinates,
        unsigned int stride,
        GLenum bufferType);

    void onRender() override;
    void setAttributeIndex(GLuint attributeIndex);
    void setActiveTextureUnit(GLenum activeTextureUnit);
    GLenum activeTextureUnit();
private:
    std::unique_ptr<GLResource> makeArrayBuffer();
private:
    std::vector<std::unique_ptr<VertexBuffer>> m_VertexBuffer;
    std::unique_ptr<GLResource> m_ArrayBuffer;
    GLuint m_AttributeIndex;
    GLenum m_ActiveTextureUnit;
};

#include "VertexArray.hpp"


#endif //NOOBYENGINE_VERTEXTARRAY_H
