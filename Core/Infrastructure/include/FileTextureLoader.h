//
// Created by Rob on 2019-08-28.
//

#ifndef NOOBYENGINE_FILETEXTURELOADER_H
#define NOOBYENGINE_FILETEXTURELOADER_H

#include "Interfaces/ITextureLoader.h"
#include "GLResource.h"

class FileTextureLoader : ITextureLoader
{
public:
    static std::unique_ptr<GLResource> loadTexture(const std::string & texturePath);
};


#endif //NOOBYENGINE_FILETEXTURELOADER_H
