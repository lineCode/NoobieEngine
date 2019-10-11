//
// Created by Rob on 2019-06-29.
//

#ifndef TUTORIALS_SHADERLOADER_H
#define TUTORIALS_SHADERLOADER_H

#include "Interfaces/IShaderLoader.h"

class ShaderLoader : public IShaderLoader
{
public:
    static std::shared_ptr<GLResource> createProgram(std::initializer_list<ShaderFileInfo> shaderInfoList);
};


#endif //TUTORIALS_SHADERLOADER_H
