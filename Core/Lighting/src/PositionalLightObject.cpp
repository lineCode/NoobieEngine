
#include "PositionalLightObject.h"
#include "external/glm-0.9.7.1/glm/gtc/matrix_transform.hpp"
#include "external/glm-0.9.7.1/glm/gtc/type_ptr.hpp"

PositionalLightObject::PositionalLightObject(std::shared_ptr<MeshObject> lightSourceModel)
    :m_lightSourceModel(lightSourceModel)
{
}

void PositionalLightObject::onRender()
{
    m_lightSourceModel->setLocation(m_location);
    m_lightSourceModel->onRender();

    m_mat = glm::translate(glm::mat4(1.0f), m_location);
    auto mvMat = m_viewMatrix * m_mat;
    m_program->setMatrix("mv_matrix", mvMat);
    m_program->setMatrix("proj_matrix", m_projectionMatrix);
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
    m_program->useProgram();
}

void PositionalLightObject::setLocation(glm::vec3 location)
{
    m_location = location;
}