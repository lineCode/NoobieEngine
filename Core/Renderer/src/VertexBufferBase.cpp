#include "VertexBufferBase.h"

VertexBufferBase::VertexBufferBase() :
    m_Count(0), m_Stride(0), m_ActiveTextureUnit(GL_TEXTURE0), 
    m_BufferType(GL_ARRAY_BUFFER), m_DrawMode(GL_TRIANGLES), m_attributeIndex(0), 
    m_textureUniformLocation(0), m_NumCopies(0), m_BufferMode(BufferMode::NoDraw)
{
}

GLuint VertexBufferBase::attributeIndex() const
{
    return m_attributeIndex;
}

GLuint VertexBufferBase::stride() const
{
    return m_Stride;
}

GLuint VertexBufferBase::drawMode() const
{
    return m_DrawMode;
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

unsigned int VertexBufferBase::count() const
{
    return m_Count;
}

unsigned int VertexBufferBase::numberOfCopies() const
{
    return m_NumCopies;
}

void VertexBufferBase::setNumberOfCopies(unsigned int numCopies)
{
    m_NumCopies = numCopies;
}

void VertexBufferBase::setAttributeIndex(GLuint attributeIndex)
{
    m_attributeIndex = attributeIndex;
}

void VertexBufferBase::setDrawMode(GLuint drawMode)
{
    m_DrawMode = drawMode;
}

void VertexBufferBase::setTextureUniformLocation(GLint textureUniformLocation)
{
    m_textureUniformLocation = textureUniformLocation;
}

void VertexBufferBase::setActiveTextureUnit(GLuint textureUnit)
{
    m_ActiveTextureUnit = textureUnit;
}