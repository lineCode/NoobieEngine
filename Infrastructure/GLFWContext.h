//
// Created by Rob on 2019-07-13.
//

#ifndef NOOBYENGINE_GLFWCONTEXT_H
#define NOOBYENGINE_GLFWCONTEXT_H

#include "../Interfaces/IContext.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class GLFWContext : public IContext{
public:
    GLFWContext();
    virtual ~GLFWContext();

    void * handle() override;
    void swapBuffer() override;
    void startContext() override;
    void endContext() override;
    int width() override;
    int height() override;
private:
    void * m_Window;
    int m_ActualWidth;
    int m_ActualHeight;
};


#endif //NOOBYENGINE_GLFWCONTEXT_H
