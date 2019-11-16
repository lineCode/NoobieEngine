#pragma once

#include "../../../Interfaces/IRenderable.h"
#include "../../Infrastructure/include/GLResource.h"
#include "BufferMode.h"

class VertexBufferBase : public IRenderable
{
public:
    VertexBufferBase();
    virtual GLuint primitiveDrawMode() const;
    virtual GLuint elementsPerComponent() const;
    virtual GLuint attributeIndex() const;
    GLuint textureHandle() const;
    virtual GLint textureUniformLocation() const;
    virtual GLenum bufferType() const;
    virtual GLenum activeTextureUnit() const;
    virtual GLuint handle() const;
    virtual unsigned int components() const;
    virtual unsigned int numberOfCopies() const;
    virtual BufferMode bufferMode() const;
    virtual unsigned int bytesToNextComponent() const;
    virtual unsigned int strideToNextComponent() const;
    virtual void setStrideToNextComponent(unsigned int strideToNextComponent);
    virtual void setBytesToNextComponent(unsigned int bytesToNextComponent);
    virtual void setNumberOfCopies(unsigned int numCopies);
    virtual void setAttributeIndex(GLuint attributeIndex);
    virtual void setPrimitiveDrawMode(GLuint primitiveDrawMode);
    virtual void setActiveTextureUnit(GLuint textureUnit);
    virtual void setTextureUniformLocation(GLint textureUniformLocation);
    virtual void onRender() = 0;
//todo: should turn this to private
protected:
    std::unique_ptr<GLResource> m_LoadedTexture;
    std::unique_ptr<GLResource> m_Buffer;
    unsigned int m_components;
    unsigned int m_elementsPerComponent;
    GLenum m_ActiveTextureUnit;
    GLenum m_BufferType;
    GLuint m_primitiveDrawMode;
    GLuint m_attributeIndex;
    GLint m_textureUniformLocation;
    unsigned int m_bytesToNextComponent;
    unsigned int m_NumCopies;
    unsigned int m_strideToNextComponent;
    BufferMode m_BufferMode;
};