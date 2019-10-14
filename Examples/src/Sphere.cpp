//
// Created by Rob on 2019-09-29.
//

#include "../../Infrastructure/include/ShaderLoader.h"
#include "../../Infrastructure/include/GLFWContext.h"
#include "../../Infrastructure/include/FileTextureLoader.h"
#include "Interfaces/IContext.h"
#include "Core/Primitives/include/SphereObject.h"
#include "Core/Renderer/include/Renderer.h"
#include "Programs/include/SphereProgram.h"

#define GL_DEBUG_CALLBACK 1

void window_reshape_callback(GLFWwindow* window, int newWidth, int newHeight)
{
    //todo: recalculate perspective matrix
}

void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
        (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
        type, severity, message);
}

void enableGlDebugCallBack()
{
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);
}

int main()
{
    std::unique_ptr<IContext> context = std::make_unique<GLFWContext>();
    context->startContext();
    
    if (GL_DEBUG_CALLBACK)
    {
        enableGlDebugCallBack();
    }

    auto handle = static_cast<GLFWwindow*>(context->handle());

    auto program = ShaderLoader::createProgram({
        ShaderFileInfo("vertShader.glsl", GL_VERTEX_SHADER),
        ShaderFileInfo("fragShader.glsl", GL_FRAGMENT_SHADER)
        });

    auto texture = FileTextureLoader::loadTexture("earth.jpg");

    int width, height;
    glfwGetFramebufferSize(handle, &width, &height);

    auto sphereProgram = std::make_shared<SphereProgram>(program);

    auto sphereObject = std::make_shared<SphereObject>(48);
    sphereObject->setTexture(std::move(texture), GL_TEXTURE0);
    sphereObject->setProgram(sphereProgram);
    sphereObject->setLocation(glm::vec3(0.0f, 0.0f, 0.0f));

    auto sphereScene = std::make_shared<Scene>(width/height);
    sphereScene->addRenderable(sphereObject);
    sphereScene->setWorldCameraLocation(glm::vec3{ 0.0f, 0.0f, -8.0f });

    Renderer renderer;
    renderer.addScene(sphereScene);
    
    do {
        renderer.render(context.get());
    } while (glfwGetKey(handle, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(handle) == 0);
}