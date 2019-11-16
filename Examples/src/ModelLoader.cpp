//
// Created by Rob on 2019-09-29.
//

#include "../../Infrastructure/include/ShaderLoader.h"
#include "../../Infrastructure/include/AssimpModelLoader.h"
#include "../../Infrastructure/include/GLFWContext.h"
#include "Programs/include/MeshProgram.h"
#include "Core/Primitives/include/MeshObject.h"
#include "Core/Renderer/include/Renderer.h"

int main()
{
    std::unique_ptr<IContext> context = std::make_unique<GLFWContext>();
    context->startContext();

    std::unique_ptr<IModelLoader> loader = std::make_unique<AssimpModelLoader>();
    auto mesh = loader->loadFromFile("monkey.obj");

    auto program = ShaderLoader::createProgram({
        ShaderFileInfo("vertShader.glsl", GL_VERTEX_SHADER),
        ShaderFileInfo("fragShader.glsl", GL_FRAGMENT_SHADER)
        });

    auto meshProgram = std::make_shared<MeshProgram>(program);
    auto meshObject = std::make_shared<MeshObject>(mesh);
    meshObject->setProgram(meshProgram);
    meshObject->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));

    auto handle = static_cast<GLFWwindow*>(context->handle());
    int width, height;
    glfwGetFramebufferSize(handle, &width, &height);

    auto mainScene = std::make_shared<Scene>(static_cast<float>(width)/static_cast<float>(height));
    mainScene->addRenderable(meshObject);
    mainScene->setWorldCameraLocation(glm::vec3{ 0.0f, 2.0f, -8.0f });
    Renderer renderer;
    renderer.addScene(mainScene);
    do {
        renderer.render(context.get());
    } while (glfwGetKey(handle, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(handle) == 0);
}
