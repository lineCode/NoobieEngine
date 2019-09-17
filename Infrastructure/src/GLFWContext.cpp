#include "include/GLFWContext.h"
//
// Created by Rob on 2019-07-13.
//

#include "include/GLFWContext.h"
#include <stdio.h>
#include <stdlib.h>

void GLFWContext::startContext() {
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit(-1);
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //mac osx required
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto window = glfwCreateWindow( 1024, 768, "Noobie Engine - Meh", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to create the window\n" );
        endContext();
        exit(-1);
    }

    glfwGetFramebufferSize(window, &m_ActualWidth, &m_ActualHeight);
    glfwMakeContextCurrent(window);
    glViewport(0,0, m_ActualWidth, m_ActualHeight);

    glfwSwapInterval(1);
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

GLFWContext::GLFWContext()
{
    m_Window = nullptr;
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

int GLFWContext::width()
{
    return m_ActualWidth;
}

int GLFWContext::height()
{
    return m_ActualHeight;
}