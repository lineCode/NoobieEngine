//
// Created by Rob on 2019-08-28.
//

#ifndef NOOBYENGINE_FILETEXTURELOADER_H
#define NOOBYENGINE_FILETEXTURELOADER_H

#include "Interfaces/ITextureLoader.h"

class FileTextureLoader : ITextureLoader
{
public:
    GLuint loadTexture(const std::string & texturePath) override ;
};


#endif //NOOBYENGINE_FILETEXTURELOADER_H
