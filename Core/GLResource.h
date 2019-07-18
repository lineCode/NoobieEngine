//
// Created by Rob on 2019-07-09.
//

#include <GL/glew.h>
#include <functional>

#ifndef TUTORIALS_GLRESOURCE_H
#define TUTORIALS_GLRESOURCE_H

class GLResource {
public:
    GLResource(GLuint resourceId, std::function<void()> deleter)
    :m_ResourceId(resourceId), m_Deleter(deleter)
    {

    }

    GLuint resourceId();
    virtual ~GLResource();

private:
    GLuint m_ResourceId;
    std::function<void()> m_Deleter;
};


#endif //TUTORIALS_GLRESOURCE_H
