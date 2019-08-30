//
// Created by Rob on 2019-08-28.
//

#ifndef NOOBYENGINE_ITEXTURELOADER_H
#define NOOBYENGINE_ITEXTURELOADER_H

#include <GL/glew.h>
#include <string>

class ITextureLoader
{
public:
    virtual GLuint loadTexture(const std::string & texturePath) = 0;
};

#endif //NOOBYENGINE_ITEXTURELOADER_H
