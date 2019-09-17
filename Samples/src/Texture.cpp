//
// Created by Rob on 2019-09-03.
//

#include "Samples/include/Texture.h"

#include <iostream>
#include "Infrastructure/include/ShaderLoader.h"
#include "Infrastructure/include/GLFWContext.h"
#include "Interfaces/IContext.h"
#include "Core/include/DrawableObject.h"
#include "Core/include/Renderer.h"
#include "Interfaces/IRenderable.h"
#include "Programs/include/CubeProgram.h"
#include "Programs/include/PlanetProgram.h"
#include "Infrastructure/include/FileTextureLoader.h"

void window_reshape_callback(GLFWwindow * window, int newWidth, int newHeight)
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
                                                      ShaderFileInfo("SimpleTransform.vertexshader", GL_VERTEX_SHADER),
                                                      ShaderFileInfo("SingleColor.fragmentshader", GL_FRAGMENT_SHADER)
        });

    FileTextureLoader textureLoader;
    auto texture = std::make_unique<GLResource>(textureLoader.loadTexture("brick1.jpg"), []()
        {
        });

    auto pyramidVertices = std::initializer_list<float>{ -1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,    //front
                                                         1.0f, -1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,    //right
                                                         1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,  //back
                                                         -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,  //left
                                                         -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, -1.0f, 1.0f, //LF
                                                         1.0f, -1.0f, 1.0f, -1.0f, -1.0f, -1.0f, 1.0f, -1.0f, -1.0f  //RR
    };

    auto pyrTexCoords = std::initializer_list<float>{
        0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f,
        0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f
    };
    int width, height;
    glfwGetFramebufferSize(handle, &width, &height);
    auto camera = std::make_shared<Camera>(
        glm::vec3{0.0f, 0.0f, -8.0f}, //location
        glm::radians<float>(59.0f), //field of view
        (float)width/(float)height, //aspect ratio
        0.1f, //near plane
        1000.0f); //far plane

    auto pyramidLocation = glm::vec3{0.0f, 0.0f, 0.0f};
    auto pyramidObj = std::make_shared<DrawableObject>(pyramidLocation, pyramidVertices, 1);
    pyramidObj->setTexture(std::move(texture), pyrTexCoords, GL_TEXTURE0);

    auto cubeProgram = std::make_shared<CubeProgram>(std::move(program),camera);
    cubeProgram->addObject(pyramidObj);

    Renderer renderer;
    renderer.setCamera(camera);
    renderer.addRenderable(cubeProgram);
    do{
        std::cout<<"Start rendering"<<std::endl;
        renderer.render(context.get());
        std::cout<<"Done rendering"<<std::endl;
    }while(glfwGetKey(handle, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(handle) == 0 );
}