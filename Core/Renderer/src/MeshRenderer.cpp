//
// Created by Rob on 2019-07-21.
//

#include "MeshRenderer.h"

MeshRenderer::MeshRenderer(std::unique_ptr<MeshDto> meshDto)
{
    m_MeshDto = std::move(meshDto);
    setupMesh(m_MeshDto.get());
}

void MeshRenderer::setupMesh(MeshDto * meshDto)
{
    m_VertexArray = std::make_unique<VertexArray>();
    m_VertexArray->addBuffer(meshDto->Vertices, 3, GL_ARRAY_BUFFER, GL_TRIANGLES);
    m_VertexArray->addBuffer<std::vector<unsigned int>>(meshDto->Indices, 3, GL_ELEMENT_ARRAY_BUFFER, GL_TRIANGLES);
}

void MeshRenderer::onRender()
{
    m_VertexArray->onRender();
}
