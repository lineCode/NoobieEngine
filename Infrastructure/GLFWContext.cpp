//
// Created by Rob on 2019-07-13.
//

#include <GL/glew.h>
#include "GLFWContext.h"
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <stdlib.h>

void GLFWContext::startContext() {
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit(-1);
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto window = glfwCreateWindow( 1024, 768, "Noobie Engine - Meh", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window. Intel GPU's are not 3.3 compatible :( \n" );
        endContext();
        exit(-1);
    }

    glfwMakeContextCurrent(window);

    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        endContext();
        exit(-1);
    }

    m_Window = window;
}

void GLFWContext::endContext() {
    glfwTerminate();
}

GLFWContext::~GLFWContext() {
    endContext();
}

void * GLFWContext::handle()
{
    return m_Window;
}

void GLFWContext::swapBuffer()
{
    auto window = static_cast<GLFWwindow*>(m_Window);
    glfwSwapBuffers(window);
    glfwPollEvents();
}
