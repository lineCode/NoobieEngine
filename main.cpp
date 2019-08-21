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

    auto pyramidVertices = std::initializer_list<float>{
        -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f
    };

    int width, height;
    glfwGetFramebufferSize(handle, &width, &height);
    auto camera = std::make_shared<Camera>(
        glm::vec3{0.0f, 0.0f, -90.0f}, //location
        glm::radians<float>(59.0f), //field of view
        (float)width/(float)height, //aspect ratio
        0.1f, //near plane
        1000.0f); //far plane

    auto objLocation = glm::vec3{0.0f, -2.0f, 0.0f};
    auto pyramidLocation = glm::vec3{-2.0f, -8.0f, 0.0f};
    auto cubeObj = std::make_shared<DrawableObject>(objLocation, objVertices, 1);
    auto pyramidObj = std::make_shared<DrawableObject>(pyramidLocation, pyramidVertices, 1);
    auto cubeProgram = std::make_shared<CubeProgram>(std::move(program), camera, cubeObj, pyramidObj);

    Renderer renderer;
    renderer.setCamera(camera);
    renderer.addRenderable(cubeProgram);
    do{
        std::cout<<"Start rendering"<<std::endl;
        renderer.render(context.get());
        std::cout<<"Done rendering"<<std::endl;
    }while(glfwGetKey(handle, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(handle) == 0 );

    return 0;
}
