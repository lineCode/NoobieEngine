//
// Created by Rob on 2019-09-29.
//

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

    auto sphereProgram = std::make_shared<SphereProgram>(std::move(program));

    auto sphereObject = std::make_shared<SphereObject>(48);
    sphereObject->setTexture(std::move(texture), GL_TEXTURE0);
    sphereObject->setProgram(sphereProgram);

    auto sphereScene = std::make_shared<Scene>(width/height);
    sphereScene->addRenderable(sphereObject);

    Renderer renderer;
    renderer.addScene(sphereScene);
    do {
        renderer.render(context.get());
    } while (glfwGetKey(handle, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(handle) == 0);
}