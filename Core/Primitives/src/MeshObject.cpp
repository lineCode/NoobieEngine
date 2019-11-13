
#include "MeshObject.h"
#include "Programs/include/MeshProgram.h"
#include "external/glm-0.9.7.1/glm/gtc/matrix_transform.hpp"
#include "external/glm-0.9.7.1/glm/gtc/type_ptr.hpp"

MeshObject::MeshObject(std::shared_ptr<std::vector<MeshDto>> meshDto)
    :m_meshDto(meshDto)
{
    unpackMesh(meshDto);
}

void MeshObject::unpackMesh(std::shared_ptr<std::vector<MeshDto> > meshDto)
{
    m_vao = std::make_unique<VertexArray>();
    for(const auto & mesh: *meshDto)
    {
        //auto vb = static_cast<VertexBufferBase*>(m_vao->addBuffer(mesh.Vertices, 2, GL_ARRAY_BUFFER, GL_TRIANGLES, 1, BufferMode::NoDraw));
        //vb->setAttributeIndex(1);
        for(auto vertex: mesh.Vertices)
        {
            //todo: make this a stride argument in vbo so no need to create extra copy
            m_vertices.push_back(vertex.Position);
        }
    }

    m_vao->addBuffer(m_vertices, 3, GL_ARRAY_BUFFER, GL_TRIANGLES);
}

void MeshObject::onRender()
{
    m_mat = glm::translate(glm::mat4(1.0f), m_location);
    auto mvMat = m_viewMatrix * m_mat;
    auto meshProgram = static_cast<MeshProgram*>(m_program.get());
    GLCall(glUniformMatrix4fv(meshProgram->modelViewMatrixLocation(), 1, GL_FALSE, glm::value_ptr(mvMat)))
    GLCall(glUniformMatrix4fv(meshProgram->projectionMatrixLocation(), 1, GL_FALSE, glm::value_ptr(m_projectionMatrix)))

    m_vao->onRender();
}

void MeshObject::setViewMatrix(glm::mat4 viewMatrix)
{
    m_viewMatrix = viewMatrix;
}

void MeshObject::setProjectionMatrix(glm::mat4 projectionMatrix)
{
    m_projectionMatrix = projectionMatrix;
}

void MeshObject::setLocation(glm::vec3 location)
{
    m_location = location;
}

void MeshObject::setProgram(std::shared_ptr<BaseProgram> program)
{
    m_program = program;
    m_program->useProgram();
}
