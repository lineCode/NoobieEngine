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

DrawableObject::DrawableObject(
    glm::vec3 location,
    const std::vector<float> & vertices,
    const std::vector<float> & textureCoor,
    unsigned int numCopies)
{
    m_Vao = std::make_unique<VertexArray>();
    m_Vao->addBuffer(vertices, 3, GL_ARRAY_BUFFER, GL_TRIANGLES, numCopies);
    m_Texture = std::make_unique<Texture>();
    m_Texture->addTexture(textureCoor, 3, GL_ARRAY_BUFFER);
}

void DrawableObject::onRender()
{
    m_Vao->setAttributeIndex(m_attributeIndex);
    m_Vao->onRender();
    m_Texture->setTextureUnit(m_activeTextureUnit);
    m_Texture->onRender();
}

glm::vec3 DrawableObject::location()
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
