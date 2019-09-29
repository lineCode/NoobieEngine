//
// Created by Rob on 2019-08-28.
//

#include "include/FileTextureLoader.h"
#include "../../../external/soil2/src/image_helper.h"
#include "../../../external/soil2/src/SOIL2.h"
#include <stdexcept>

GLuint FileTextureLoader::loadTexture(const std::string & texturePath)
{
    GLuint textureID = SOIL_load_OGL_texture(texturePath.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if (!textureID)
    {
        throw std::invalid_argument(SOIL_last_result());
    }
    return textureID;
}
