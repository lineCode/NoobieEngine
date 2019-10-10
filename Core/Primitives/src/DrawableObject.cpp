//
// Created by Rob on 2019-07-13.
//

#include "Primitives/include/DrawableObject.h"

DrawableObject::DrawableObject(glm::vec3 location, const std::vector<float> & vertices, unsigned int numCopies):
    m_Location(location), m_Vertices(vertices), m_NumCopies(numCopies)
{
    m_Vao = std::make_unique<VertexArray>();
    auto buffer = m_Vao->addBuffer(vertices, 3, GL_ARRAY_BUFFER, GL_TRIANGLES);
    buffer->setAttributeIndex(0);
}

void DrawableObject::onRender()
{
    m_Vao->onRender();
}

void DrawableObject::setTexture(std::unique_ptr<GLResource> loadedTexture, const std::vector<float>& textureCoordinates, GLenum activeTextureUnit)
{
    auto buffer = m_Vao->addTexture(std::move(loadedTexture), textureCoordinates, 2, GL_ARRAY_BUFFER);
    buffer->setAttributeIndex(1);
    buffer->setActiveTextureUnit(activeTextureUnit);
}

glm::vec3 DrawableObject::location() const
{
    return m_Location;
}

void DrawableObject::setAttributeIndex(GLuint attributeLocation)
{
    m_attributeIndex = attributeLocation;
}