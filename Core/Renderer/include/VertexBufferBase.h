#pragma once

#include "../../../Interfaces/IRenderable.h"
#include "../../Infrastructure/include/GLResource.h"
#include "BufferMode.h"

class VertexBufferBase : public IRenderable
{
public:
    VertexBufferBase() = default;
    virtual GLuint drawMode() const;
    virtual GLuint stride() const;
    virtual GLuint attributeIndex() const;
    GLuint textureHandle() const;
    virtual GLint textureUniformLocation() const;
    virtual GLenum bufferType() const;
    virtual GLenum activeTextureUnit() const;
    virtual GLuint handle() const;
    virtual unsigned int count() const;
    virtual unsigned int numberOfCopies() const;
    virtual BufferMode bufferMode() const;
    virtual void setNumberOfCopies(unsigned int numCopies);
    virtual void setAttributeIndex(GLuint attributeIndex);
    virtual void setDrawMode(GLuint drawMode);
    virtual void setActiveTextureUnit(GLuint textureUnit);
    virtual void setTextureUniformLocation(GLint textureUniformLocation);
    virtual void onRender() = 0;
protected:
    std::unique_ptr<GLResource> m_LoadedTexture;
    std::unique_ptr<GLResource> m_Buffer;
    unsigned int m_Count;
    unsigned int m_Stride;
    GLenum m_ActiveTextureUnit;
    GLenum m_BufferType;
    GLuint m_DrawMode;
    GLuint m_attributeIndex;
    GLint m_textureUniformLocation;
    unsigned int m_NumCopies;
    BufferMode m_BufferMode;
};