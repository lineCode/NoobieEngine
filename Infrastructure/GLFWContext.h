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
private:
    void * m_Window;

};


#endif //NOOBYENGINE_GLFWCONTEXT_H
