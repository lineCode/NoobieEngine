//
// Created by Rob on 2019-08-11.
//

#include "CubeProgram.h"
#include "external/glm-0.9.7.1/glm/gtc/matrix_transform.hpp"
#include "external/glm-0.9.7.1/glm/gtc/type_ptr.hpp"
#include "Infrastructure/ShaderLoader.h"

CubeProgram::CubeProgram(std::unique_ptr<GLResource> program, std::shared_ptr<Camera> camera) :
    BaseProgram(std::move(program), camera)
{
}

void CubeProgram::onRender()
{
    BaseProgram::onRender();
    for (const auto & object : m_Objects)
    {
        GLint projLoc;
        GLint mvLoc;
        auto vMat = glm::translate(glm::mat4(1.0f), m_Camera->location());
        auto mMat = glm::translate(glm::mat4(1.0f), m_Camera->location());

        mMat = glm::rotate(mMat, -0.45f, glm::vec3(1.0f, 0.0f, 0.0f));
        mMat = glm::rotate(mMat, 0.61f, glm::vec3(0.0f, 1.0f, 0.0f));
        mMat = glm::rotate(mMat, 0.00f, glm::vec3(0.0f, 0.0f, 1.0f));

        auto mvMat = vMat * mMat;

        GLCall(mvLoc = glGetUniformLocation(m_Program->resourceId(), "mv_matrix"))
        GLCall(projLoc = glGetUniformLocation(m_Program->resourceId(), "proj_matrix"))
        GLCall(glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvMat)))
        GLCall(glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(m_Camera->perspectiveMatrix())))

        object->onRender();
    }
}

GLuint CubeProgram::programId()
{
    return m_Program->resourceId();
}

void CubeProgram::addObject(std::shared_ptr<DrawableObject> object)
{
    m_Objects.push_back(std::move(object));
}
