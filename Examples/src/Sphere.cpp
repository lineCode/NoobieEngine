//
// Created by Rob on 2019-09-29.
//

#include <iostream>
#include "../../Infrastructure/include/ShaderLoader.h"
#include "../../Infrastructure/include/GLFWContext.h"
#include "../../Infrastructure/include/FileTextureLoader.h"
#include "Interfaces/IContext.h"
#include "Core/Renderer/include/SphereObject.h"
#include "Core/Renderer/include/Renderer.h"
#include "Programs/include/SphereProgram.h"

void window_reshape_callback(GLFWwindow* window, int newWidth, int newHeight)
{
    //todo: recalculate perspective matrix
}


int main()
{
    std::unique_ptr<IContext> context = std::make_unique<GLFWContext>();
    context->startContext();
    auto handle = static_cast<GLFWwindow*>(context->handle());

    ShaderLoader loader;
    auto program = loader.createProgram({
                                                      ShaderFileInfo("vertShader.glsl", GL_VERTEX_SHADER),
                                                      ShaderFileInfo("fragShader.glsl", GL_FRAGMENT_SHADER)
        });

    FileTextureLoader textureLoader;
    auto texture = std::make_unique<GLResource>(textureLoader.loadTexture("earth.jpg"), []()
        {
        });

    int width, height;
    glfwGetFramebufferSize(handle, &width, &height);
    auto camera = std::make_shared<Camera>(
        glm::vec3{ 0.0f, 0.0f, -8.0f }, //location
        glm::radians<float>(59.0f), //field of view
        (float)width / (float)height, //aspect ratio
        0.1f, //near plane
        1000.0f); //far plane

    auto sphereObject = std::make_shared<SphereObject>(48);
    sphereObject->setTexture(std::move(texture), GL_TEXTURE0);

    auto sphereProgram = std::make_shared<SphereProgram>(std::move(program), camera);
    sphereProgram->addObject(sphereObject);

    Renderer renderer;
    renderer.setCamera(camera);
    renderer.addRenderable(sphereProgram);
    do {
        std::cout << "Start rendering" << std::endl;
        renderer.render(context.get());
        std::cout << "Done rendering" << std::endl;
    } while (glfwGetKey(handle, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(handle) == 0);
}