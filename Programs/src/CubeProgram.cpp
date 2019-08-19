//
// Created by Rob on 2019-08-11.
//

#include <Programs/include/CubeProgram.h>

#include "CubeProgram.h"
#include "external/glm-0.9.7.1/glm/gtc/matrix_transform.hpp"
#include "external/glm-0.9.7.1/glm/gtc/type_ptr.hpp"

CubeProgram::CubeProgram(
    std::unique_ptr<GLResource> program,
    std::shared_ptr<Camera> camera,
    std::shared_ptr<DrawableObject> cubeObject)
:m_Program(std::move(program)), m_Camera(camera), m_CubeObject(cubeObject)
{
}

void CubeProgram::onRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLCall(glUseProgram(m_Program->resourceId()));

    GLint mLoc;
    GLint vLoc;
    GLint projLoc;
    GLCall(mLoc = glGetUniformLocation(m_Program->resourceId(), "m_matrix"));
    GLCall(vLoc = glGetUniformLocation(m_Program->resourceId(), "v_matrix"));
    GLCall(projLoc = glGetUniformLocation(m_Program->resourceId(), "proj_matrix"));
    GLCall(glUniformMatrix4fv(mLoc, 1, GL_FALSE, glm::value_ptr(modelMat())));
    GLCall(glUniformMatrix4fv(vLoc, 1, GL_FALSE, glm::value_ptr(viewMat())));
    GLCall(glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(m_Camera->perspectiveMatrix())));

    double timeFactor = glfwGetTime();
    auto tfLoc = glGetUniformLocation(m_Program->resourceId(), "tf");
    glUniform1f(tfLoc, (float)timeFactor);

    m_CubeObject->onRender();
}

glm::mat4 CubeProgram::viewMat()
{
    return glm::translate(glm::mat4(1.0f), m_Camera->location());
}

glm::mat4 CubeProgram::modelMat()
{
    double currentTime = glfwGetTime();
    auto tf = currentTime;
    auto tfLoc = glGetUniformLocation(m_Program->resourceId(), "tf");
    glUniform1f(tfLoc, (float)tf);

    glm::mat4 tMat = glm::translate(glm::mat4(1.0f), glm::vec3(sin(0.35f * tf) * 8.0f, cos(0.52f*tf) * 8.0f, sin(0.7f*tf)*8.0f));
    glm::mat4 rMat = glm::rotate(glm::mat4(1.0f), 1.75f*(float)currentTime, glm::vec3(0.0f, 1.0f, 0.0f));
    rMat = glm::rotate(rMat, 1.75f*(float)currentTime, glm::vec3(1.0f, 0.0f, 0.0f));
    rMat = glm::rotate(rMat, 1.75f*(float)currentTime, glm::vec3(0.0f, 0.0f, 1.0f));
    auto mMat = tMat * rMat;

    return mMat;
}

GLuint CubeProgram::programId()
{
    return m_Program->resourceId();
}
