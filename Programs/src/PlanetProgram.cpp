//
// Created by Rob on 2019-08-22.
//

#include "PlanetProgram.h"
#include "Infrastructure/GLFWContext.h"

#include <stack>

PlanetProgram::PlanetProgram(
    std::unique_ptr<GLResource> program,
    std::shared_ptr<Camera> camera)
:m_Program(std::move(program)), m_Camera(camera)
{

}

void PlanetProgram::onRender()
{
    GLint mvLoc;
    GLCall(mvLoc = glGetUniformLocation(m_Program->resourceId(), "mv_matrix"));

    double currentTime = glfwGetTime();
    std::stack<glm::mat4> mvStack;

    auto vMat = glm::translate(glm::mat4(1.0f), m_Camera->location());
    mvStack.push(vMat);

    //sun
    mvStack.push(mvStack.top());
    mvStack.top() *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
    mvStack.push(mvStack.top());
    mvStack.top() *= glm::rotate(glm::mat4(1.0f), (float)currentTime, glm::vec3(1.0f, 0.0f, 0.0f));

    GLCall(glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top())));
    m_Objects[0]->onRender(); //assume sun is first
    mvStack.pop();

    //cube
    mvStack.push(mvStack.top());
    mvStack.top() *= glm::translate(glm::mat4(1.0f), glm::vec3(sin((float) currentTime)*4.0, 0.0f, cos((float)currentTime)*4.0));
    mvStack.push(mvStack.top());
    mvStack.top() *= glm::rotate(glm::mat4(1.0f), (float)currentTime, glm::vec3(0.0, 1.0, 0.0));
    GLCall(glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top())));
    m_Objects[1]->onRender();
    mvStack.pop();

    //smaller cube moon
    mvStack.push(mvStack.top());
    mvStack.top() *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, sin((float)currentTime)*2.0, cos((float)currentTime)*2.0));
    mvStack.top() *= glm::rotate(glm::mat4(1.0f), (float)currentTime, glm::vec3(0.0, 0.0, 1.0));
    mvStack.top() *= glm::scale(glm::mat4(1.0f), glm::vec3(0.25f, 0.25f, 0.25f));
    GLCall(glUniformMatrix4fv(mvLoc, 1, GL_FALSE, glm::value_ptr(mvStack.top())));
    m_Objects[2]->onRender();
    mvStack.pop();
    mvStack.pop();
    mvStack.pop();
    mvStack.pop();
}

void PlanetProgram::addObject(std::shared_ptr<DrawableObject> object)
{
    m_Objects.push_back(std::move(object));
}
