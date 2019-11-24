
#include "PositionalLightObject.h"
#include "Programs/include/MeshProgram.h"
#include "external/glm-0.9.7.1/glm/gtc/matrix_transform.hpp"
#include "external/glm-0.9.7.1/glm/gtc/type_ptr.hpp"

PositionalLightObject::PositionalLightObject(std::shared_ptr<MeshObject> lightSourceModel)
    :m_lightSourceModel(lightSourceModel)
{
}

void PositionalLightObject::onRender()
{
    m_program->useProgram();
    m_lightSourceModel->setLocation(m_location);
    m_lightSourceModel->onRender();
    m_mat = glm::translate(glm::mat4(1.0f), m_location);
    auto mvMat = m_viewMatrix * m_mat;
    auto meshProgram = static_cast<MeshProgram*>(m_program.get());
    GLCall(glUniformMatrix4fv(meshProgram->modelViewMatrixLocation(), 1, GL_FALSE, glm::value_ptr(mvMat)))
    GLCall(glUniformMatrix4fv(meshProgram->projectionMatrixLocation(), 1, GL_FALSE, glm::value_ptr(m_projectionMatrix)))
    m_vao->onRender();
}
void PositionalLightObject::setViewMatrix(glm::mat4 viewMatrix)
{
    m_viewMatrix = viewMatrix;
}
void PositionalLightObject::setProjectionMatrix(glm::mat4 projectionMatrix)
{
    m_projectionMatrix = projectionMatrix;
}

void PositionalLightObject::setProgram(std::shared_ptr<BaseProgram> program)
{
    m_program = program;
}

void PositionalLightObject::setLocation(glm::vec3 location)
{
    m_location = location;
}