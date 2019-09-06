//
// Created by Rob on 2019-07-14.
//

#ifndef NOOBYENGINE_VERTEXBUFFER_H
#define NOOBYENGINE_VERTEXBUFFER_H

#include "BufferMode.h"
#include "../Infrastructure/GLResource.h"
#include "../Interfaces/IRenderable.h"
#include "../Infrastructure/GLSafe.h"
#include <glm/glm.hpp>
#include <vector>
#include <memory>


class VertexBuffer : IRenderable{
public:
    VertexBuffer();
    unsigned int count() const;
    GLuint handle() const;
    unsigned stride() const;
    template<typename T> void makeBuffer(
        const std::vector<T> & vertices,
        unsigned int stride,
        GLenum bufferType);
    template<typename T> void makeBuffer(
        const std::vector<T> & vertices,
        unsigned int stride,
        GLenum bufferType,
        BufferMode bufferMode);
    template<typename T> void makeTexture(
        std::unique_ptr<GLResource> loadedTexture,
        const std::vector<T> & textureCoordinates,
        unsigned int stride,
        GLenum bufferType);

    BufferMode bufferMode() const;
    void setNumberOfCopies(unsigned int numCopies);
    unsigned int numberOfCopies() const;

    GLuint attributeIndex() const;
    void setAttributeIndex(GLuint attributeIndex);

    GLuint drawMode() const;
    void setDrawMode(GLuint drawMode);

    GLenum activeTextureUnit() const;
    void setActiveTextureUnit(GLuint textureUnit);

    GLenum bufferType() const;
    void setBufferType(GLenum bufferType);

    void onRender() override;
private:
    void drawArrays();
private:
    std::unique_ptr<GLResource> m_Buffer;
    std::unique_ptr<GLResource> m_LoadedTexture;
    unsigned int m_Count;
    unsigned int m_Stride;
    GLenum m_ActiveTextureUnit;
    GLenum m_BufferType;
    GLuint m_DrawMode;
    GLuint m_attributeIndex;
    unsigned int m_NumCopies;
    BufferMode m_BufferMode;
};

#include "VertexBuffer.hpp"

#endif //NOOBYENGINE_VERTEXBUFFER_H
