//
// Created by Rob on 2019-07-21.
//

#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<TextureDto> textures)
{
    m_Vertices = vertices;
    m_Indices = indices;
    m_Textures = textures;
    setupMesh(vertices, indices);
}

void Mesh::setupMesh(const std::vector<Vertex> & vertices, std::vector<unsigned int> indices)
{
    m_VertexArray = std::make_unique<VertexArray>();
    m_VertexArray->addBuffer(vertices, 3, GL_ARRAY_BUFFER, GL_TRIANGLES);
    m_VertexArray->addBuffer<std::vector<unsigned int>>(indices, 3, GL_ELEMENT_ARRAY_BUFFER, GL_TRIANGLES);
}

void Mesh::onRender()
{
    m_VertexArray->onRender();
}
