//
// Created by Rob on 2019-08-11.
//

#include <Programs/include/CubeProgram.h>

#include "CubeProgram.h"
#include "external/glm-0.9.7.1/glm/gtc/matrix_transform.hpp"
#include "external/glm-0.9.7.1/glm/gtc/type_ptr.hpp"

void CubeProgram::onRender()
{
    glm::mat4 pMat, vMat, mMat, mvMat;
    GLCall(glUseProgram(m_Program->resourceId()));
    auto cameraLocation = m_Camera->location();
    auto cubeLocation = m_CubeObject->location();

    auto mvLoc = glGetUniformLocation(m_Program->resourceId(), "mv_matrix");
    auto projLoc = glGetUniformLocation(m_Program->resourceId(), "proj_matrix");
    int width, height;
    glfwGetFramebufferSize(m_GlfwWindow, &width, &height);
    auto aspect = static_cast<float>(width) / static_cast<float>(height);
    pMat = glm::perspective(1.0472f, aspect, 0.1f, 1000.0f);
    vMat = glm::translate(glm::mat4(1.0f), glm::vec3(-cameraLocation[0], -cameraLocation[1], -cameraLocation[2]));
    mMat = glm::translate(glm::mat4(1.0f), glm::vec3(cubeLocation[0], cubeLocation[1], cubeLocation[2]));
    mvMat = vMat * mMat;
    glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvMat));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(pMat));
}

CubeProgram::CubeProgram(
    std::unique_ptr<GLResource> program,
    GLFWwindow *window,
    std::shared_ptr<Camera> camera,
    std::shared_ptr<DrawableObject> cubeObject)
:m_Program(std::move(program)), m_GlfwWindow(window), m_Camera(camera), m_CubeObject(cubeObject)
{

}

GLuint CubeProgram::programId()
{
    return m_Program->resourceId();
}
