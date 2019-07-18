#include <iostream>
#include "Infrastructure/ShaderLoader.h"
#include "Infrastructure/GLFWContext.h"
#include "Interfaces/IContext.h"
#include "Core/VertexArray.h"
#include "Core/Renderer.h"

int main()
{
    std::unique_ptr<IContext> context = std::make_unique<GLFWContext>();
    context->startContext();

    auto program = createShaderProgram(
        {
            ShaderFileInfo("SimpleTransform.vertexshader", GL_VERTEX_SHADER),
            ShaderFileInfo("SingleColor.fragmentshader", GL_FRAGMENT_SHADER)
        });

    auto points =
        {
            glm::vec3(-1.0f, -1.0f, 0.0),
            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec3(1.0f, -1.0f, 0.0f)
        };

    auto arrayBuffer = std::make_unique<VertexArray>(points);
    auto renderer = std::make_unique<Renderer>(std::move(program), std::move(arrayBuffer));

    auto handle = static_cast<GLFWwindow*>(context->handle());
    do{
        renderer->render(context.get());
    }while(glfwGetKey(handle, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(handle) == 0 );

    return 0;
}