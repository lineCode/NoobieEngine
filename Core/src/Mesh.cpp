//
// Created by Rob on 2019-07-21.
//

#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures)
{
    m_Vertices = vertices;
    m_Indices = indices;
    m_Textures = textures;
    setupMesh(vertices, indices);
}

void Mesh::setupMesh(const std::vector<Vertex> & vertices, std::vector<unsigned int> indices)
{
    m_VertexArray = std::make_unique<VertexArray>();
    m_VertexArray->addBuffer(vertices, GL_ARRAY_BUFFER);
    m_VertexArray->addBuffer<std::vector<unsigned int>>(indices, GL_ELEMENT_ARRAY_BUFFER);
}

void Mesh::onRender()
{
    m_VertexArray->onRender();
}
