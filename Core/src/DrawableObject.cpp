//
// Created by Rob on 2019-07-13.
//

#include "DrawableObject.h"

DrawableObject::DrawableObject(glm::vec3 location, const std::vector<float> & vertices, unsigned int numCopies):
    m_Location(location), m_Vertices(vertices), m_NumCopies(numCopies)
{
    m_Vao = std::make_unique<VertexArray>();
    m_Vao->addBuffer(vertices, 3, GL_ARRAY_BUFFER, GL_TRIANGLES, numCopies);
}

void DrawableObject::onRender()
{
    m_Vao->setAttributeIndex(m_attributeIndex);
    m_Vao->setActiveTextureUnit(m_activeTextureUnit);
    m_Vao->onRender();
}

void DrawableObject::setTexture(std::unique_ptr<GLResource> loadedTexture, const std::vector<float>& textureCoordinates)
{
    m_Vao->addTexture(std::move(loadedTexture), textureCoordinates, 2, GL_ARRAY_BUFFER);
}

glm::vec3 DrawableObject::location() const
{
    return m_Location;
}

void DrawableObject::setAttributeIndex(GLuint attributeLocation)
{
    m_attributeIndex = attributeLocation;
}

void DrawableObject::setActiveTextureUnit(GLuint textureUnit)
{
    m_activeTextureUnit = textureUnit;
}
