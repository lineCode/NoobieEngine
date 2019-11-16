#include "VertexBufferBase.h"

VertexBufferBase::VertexBufferBase() :
    m_components(0), m_bytesToNextComponent(0), m_strideToNextComponent(0), m_elementsPerComponent(0), m_ActiveTextureUnit(GL_TEXTURE0),
    m_BufferType(GL_ARRAY_BUFFER), m_primitiveDrawMode(GL_TRIANGLES), m_attributeIndex(0),
    m_textureUniformLocation(0), m_NumCopies(1), m_BufferMode(BufferMode::NoDraw)
{
}

GLuint VertexBufferBase::attributeIndex() const
{
    return m_attributeIndex;
}

GLuint VertexBufferBase::bytesToNextComponent() const
{
    return m_bytesToNextComponent;
}

GLuint VertexBufferBase::elementsPerComponent() const
{
    return m_elementsPerComponent;
}

GLuint VertexBufferBase::primitiveDrawMode() const
{
    return m_primitiveDrawMode;
}

GLenum VertexBufferBase::bufferType() const
{
    return m_BufferType;
}

GLenum VertexBufferBase::activeTextureUnit() const
{
    return m_ActiveTextureUnit;
}

GLuint VertexBufferBase::handle() const
{
    return m_Buffer->resourceId();
}

GLint VertexBufferBase::textureUniformLocation() const
{
    return m_textureUniformLocation;
}

GLuint VertexBufferBase::textureHandle() const
{
    return m_LoadedTexture->resourceId();
}

BufferMode VertexBufferBase::bufferMode() const
{
    return m_BufferMode;
}

unsigned int VertexBufferBase::components() const
{
    return m_components;
}

unsigned int VertexBufferBase::numberOfCopies() const
{
    return m_NumCopies;
}

unsigned int VertexBufferBase::strideToNextComponent() const
{
    return m_strideToNextComponent;
}

void VertexBufferBase::setStrideToNextComponent(unsigned int strideToNextComponent)
{
    m_strideToNextComponent = strideToNextComponent;
}

void VertexBufferBase::setBytesToNextComponent(unsigned int bytesToNextComponent)
{
    m_bytesToNextComponent = bytesToNextComponent;
}

void VertexBufferBase::setNumberOfCopies(unsigned int numCopies)
{
    m_NumCopies = numCopies;
}

void VertexBufferBase::setAttributeIndex(GLuint attributeIndex)
{
    m_attributeIndex = attributeIndex;
}

void VertexBufferBase::setPrimitiveDrawMode(GLuint primitiveDrawMode)
{
    m_primitiveDrawMode = primitiveDrawMode;
}

void VertexBufferBase::setTextureUniformLocation(GLint textureUniformLocation)
{
    m_textureUniformLocation = textureUniformLocation;
}

void VertexBufferBase::setActiveTextureUnit(GLuint textureUnit)
{
    m_ActiveTextureUnit = textureUnit;
}