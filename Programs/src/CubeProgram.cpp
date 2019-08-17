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
    GLint vMat;
    GLCall(vMat = glGetUniformLocation(m_Program->resourceId(), "v_matrix"));
    double timeFactor = glfwGetTime();
    auto tfLoc = glGetUniformLocation(m_Program->resourceId(), "tf");
    glUniform1f(tfLoc, (float)timeFactor);

    m_CubeObject->onRender();
}

glm::mat4 CubeProgram::modelView(int offset)
{
    auto cameraLocation = m_Camera->location();
    auto vMat = glm::translate(glm::mat4(1.0f), glm::vec3(cameraLocation[0], cameraLocation[1], cameraLocation[2]));
    double currentTime = glfwGetTime();
    auto tf = currentTime + offset;
    glm::mat4 tMat = glm::translate(glm::mat4(1.0f), glm::vec3(sin(0.35f * tf) * 8.0f, cos(0.52f*tf) * 8.0f, sin(0.7f*tf)*8.0f));
    glm::mat4 rMat = glm::rotate(glm::mat4(1.0f), 1.75f*(float)currentTime, glm::vec3(0.0f, 1.0f, 0.0f));
    rMat = glm::rotate(rMat, 1.75f*(float)currentTime, glm::vec3(1.0f, 0.0f, 0.0f));
    rMat = glm::rotate(rMat, 1.75f*(float)currentTime, glm::vec3(0.0f, 0.0f, 1.0f));
    auto mMat = tMat * rMat;

    return vMat * mMat;
}

GLuint CubeProgram::programId()
{
    return m_Program->resourceId();
}
