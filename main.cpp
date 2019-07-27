#include <iostream>
#include "Infrastructure/ShaderLoader.h"
#include "Infrastructure/GLFWContext.h"
#include "Interfaces/IContext.h"
#include "Core/VertexArray.h"
#include "Core/Renderer.h"
#include "Interfaces/IRenderable.h"
int main()
{
    std::unique_ptr<IContext> context = std::make_unique<GLFWContext>();
    context->startContext();

    auto program = createShaderProgram(
        {
            ShaderFileInfo("SimpleTransform.vertexshader", GL_VERTEX_SHADER),
            ShaderFileInfo("SingleColor.fragmentshader", GL_FRAGMENT_SHADER)
        });


    auto handle = static_cast<GLFWwindow*>(context->handle());
    std::vector<float> vertices ={
        0.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f
    };

    auto va = std::make_unique<VertexArray>();
    va->addBuffer(vertices, GL_ARRAY_BUFFER);
    Renderer renderer(program->resourceId());
    do{
        renderer.render(context.get(), (IRenderable*)va.get());
    }while(glfwGetKey(handle, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(handle) == 0 );

    return 0;
}