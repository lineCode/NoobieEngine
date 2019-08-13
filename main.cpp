#include <iostream>
#include "Infrastructure/ShaderLoader.h"
#include "Infrastructure/GLFWContext.h"
#include "Interfaces/IContext.h"
#include "Core/include/DrawableObject.h"
#include "Core/include/Renderer.h"
#include "Interfaces/IRenderable.h"
#include "Programs/include/CubeProgram.h"


int main()
{
    std::unique_ptr<IContext> context = std::make_unique<GLFWContext>();
    context->startContext();
    auto handle = static_cast<GLFWwindow*>(context->handle());

    auto program = createShaderProgram(
        {
            ShaderFileInfo("SimpleTransform.vertexshader", GL_VERTEX_SHADER),
            ShaderFileInfo("SingleColor.fragmentshader", GL_FRAGMENT_SHADER)
        });

    auto objVertices = std::initializer_list<float>{
        -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
    };

    auto camera = std::make_shared<Camera>(glm::vec3{0.0f, 0.0f, -8.0f});
    auto objLocation = glm::vec3{0.0f, -2.0f, 0.0f};
    auto cubeObj = std::make_shared<DrawableObject>(objLocation, objVertices);
    auto cubeProgram = std::make_shared<CubeProgram>(std::move(program), handle, camera, cubeObj);

    Renderer renderer(cubeProgram->programId());
    renderer.setCamera(camera);
    renderer.addRenderable(cubeProgram);
    renderer.addRenderable(cubeObj);
    do{
        std::cout<<"Start rendering"<<std::endl;
        renderer.render(context.get());
        std::cout<<"Done rendering"<<std::endl;
    }while(glfwGetKey(handle, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(handle) == 0 );

    return 0;
}
