#include <iostream>
#include "Infrastructure/ShaderLoader.h"
#include "Infrastructure/GLFWContext.h"
#include "Interfaces/IContext.h"
#include "Core/include/DrawableObject.h"
#include "Core/include/Renderer.h"
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

    auto objVertices = std::initializer_list<float>{
        0.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f

    };
    auto objLocation = glm::vec3{0.0f, -2.0f, 0.0f};
    auto drawableObj = std::make_unique<DrawableObject>(objLocation, objVertices);

    auto camera = std::make_shared<Camera>(glm::vec3{0.0f, 0.0f, 8.0f});
    Renderer renderer(program->resourceId());
    renderer.setCamera(camera);
    do{
        renderer.render(context.get(), (IRenderable*)drawableObj.get());
    }while(glfwGetKey(handle, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(handle) == 0 );

    return 0;
}