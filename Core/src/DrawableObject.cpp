//
// Created by Rob on 2019-07-13.
//

#include "Object.h"

DrawableObject::DrawableObject(std::vector<float> vertices):
    m_Vertices(vertices)
{
    m_Vao = std::make_unique<VertexArray>();
    m_Vao->addBuffer(vertices, GL_ARRAY_BUFFER);
}

void DrawableObject::onRender()
{

}
