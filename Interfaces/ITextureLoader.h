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
    static GLuint loadTexture(const std::string & texturePath);
};

#endif //NOOBYENGINE_ITEXTURELOADER_H
