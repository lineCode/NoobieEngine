//
// Created by Rob on 2019-07-14.
//

#include "VertexArray.h"

VertexArray::VertexArray()
{
    m_ArrayBuffer = makeArrayBuffer();
}

std::unique_ptr<GLResource> VertexArray::makeArrayBuffer()
{
    GLuint vertexArrayId;
    GLCall(glGenVertexArrays(1, &vertexArrayId));
    GLCall(glBindVertexArray(vertexArrayId));
    return std::make_unique<GLResource>(vertexArrayId, [vertexArrayId]()
    {
        glDeleteVertexArrays(1, &vertexArrayId);
    });
}

GLuint VertexArray::handle()
{
    return m_ArrayBuffer->resourceId();
}

void VertexArray::onRender()
{
    GLCall(glEnableVertexAttribArray(m_AttributeIndex));
    for(auto & vertexBuffer : m_VertexBuffer)
    {
        vertexBuffer->setAttributeIndex(m_AttributeIndex);
        vertexBuffer->setActiveTextureUnit(m_ActiveTextureUnit);
        vertexBuffer->onRender();
    }
}

void VertexArray::setAttributeIndex(GLuint attributeIndex)
{
    m_AttributeIndex = attributeIndex;
}

void VertexArray::setActiveTextureUnit(GLenum activeTextureUnit)
{
    m_ActiveTextureUnit = activeTextureUnit;
}

GLenum VertexArray::activeTextureUnit()
{
    return m_ActiveTextureUnit;
}