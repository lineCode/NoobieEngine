//
// Created by Rob on 2019-08-11.
//

#include "CubeProgram.h"
#include "external/glm-0.9.7.1/glm/gtc/matrix_transform.hpp"
#include "external/glm-0.9.7.1/glm/gtc/type_ptr.hpp"
#include "Infrastructure/ShaderLoader.h"

CubeProgram::CubeProgram(std::shared_ptr<Camera> camera)
:BaseProgram(camera)
{
    ShaderLoader loader;
    BaseProgram::m_Program = loader.createProgram({
                                                      ShaderFileInfo("SimpleTransform.vertexshader", GL_VERTEX_SHADER),
                                                      ShaderFileInfo("SingleColor.fragmentshader", GL_FRAGMENT_SHADER)
                                                  });
}

void CubeProgram::onRender()
{
    BaseProgram::onRender();
    for (const auto & object : m_Objects)
    {
        GLint vLoc;
        GLint projLoc;
        GLint tLoc;
        auto tmatrix = glm::translate(glm::mat4(1.0f), object->location());
        auto vmatrix = glm::translate(glm::mat4(1.0f), m_Camera->location());

        object->setAttributeIndex(0);
        GLCall(tLoc = glGetUniformLocation(m_Program->resourceId(), "t_matrix"));
        GLCall(vLoc = glGetUniformLocation(m_Program->resourceId(), "v_matrix"));
        GLCall(projLoc = glGetUniformLocation(m_Program->resourceId(), "proj_matrix"));
        GLCall(glUniformMatrix4fv(tLoc, 1, GL_FALSE, glm::value_ptr(tmatrix)));
        GLCall(glUniformMatrix4fv(vLoc, 1, GL_FALSE, glm::value_ptr(vmatrix)));
        GLCall(glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(m_Camera->perspectiveMatrix())));

        double currentTime = glfwGetTime();
        auto tf = currentTime;
        GLint tfLoc;
        GLCall(tfLoc = glGetUniformLocation(m_Program->resourceId(), "tf"));
        GLCall(glUniform1f(tfLoc, (float)tf));
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
