//
// Created by Rob on 2019-07-13.
//

#include "DrawableObject.h"

DrawableObject::DrawableObject(glm::vec3 location, std::vector<float> vertices, unsigned int numCopies):
    m_Location(location), m_Vertices(vertices), m_NumCopies(numCopies)
{
    m_Vao = std::make_unique<VertexArray>();
    m_Vao->addBuffer(vertices, 3, GL_ARRAY_BUFFER, GL_TRIANGLES, numCopies);
}

void DrawableObject::onRender()
{
    m_Vao->onRender();
}

glm::vec3 DrawableObject::location()
{
    return m_Location;
}
