#include <iostream>
#include "Infrastructure/ShaderLoader.h"
#include "Infrastructure/GLFWContext.h"
#include "Interfaces/IContext.h"
#include "Core/include/DrawableObject.h"
#include "Core/include/Renderer.h"
#include "Interfaces/IRenderable.h"
#include "Programs/include/CubeProgram.h"
#include "Programs/include/PlanetProgram.h"

int main()
{
    std::unique_ptr<IContext> context = std::make_unique<GLFWContext>();
    context->startContext();
    auto handle = static_cast<GLFWwindow*>(context->handle());

    auto program = createShaderProgram(
        {
            ShaderFileInfo("vertShader.glsl", GL_VERTEX_SHADER),
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

    auto pyramidVertices = std::initializer_list<float>{ -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,    //front
        1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,    //right
        1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,  //back
        -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,  //left
        -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, //LF
        1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f  //RR
    };

    int width, height;
    glfwGetFramebufferSize(handle, &width, &height);
    auto camera = std::make_shared<Camera>(
        glm::vec3{0.0f, 0.0f, -20.0f}, //location
        glm::radians<float>(59.0f), //field of view
        (float)width/(float)height, //aspect ratio
        0.1f, //near plane
        1000.0f); //far plane

    auto objLocation = glm::vec3{0.0f, -2.0f, 0.0f};
    auto pyramidLocation = glm::vec3{-8.0f, -8.0f, 0.0f};
    auto cubeObj = std::make_shared<DrawableObject>(objLocation, objVertices, 1);
    auto pyramidObj = std::make_shared<DrawableObject>(pyramidLocation, pyramidVertices, 1);

    auto cubeProgram = std::make_shared<PlanetProgram>(std::move(program), camera);
    cubeProgram->addObject(pyramidObj);
    cubeProgram->addObject(cubeObj);
    cubeProgram->addObject(cubeObj);

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
