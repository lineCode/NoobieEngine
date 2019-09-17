//
// Created by Rob on 2019-06-29.
//

#ifndef TUTORIALS_SHADERLOADER_H
#define TUTORIALS_SHADERLOADER_H

#include "../../Interfaces/IShaderLoader.h"

class ShaderLoader : public IShaderLoader
{
public:
    std::unique_ptr<GLResource> createProgram(std::initializer_list<ShaderFileInfo> shaderInfoList) override;
};


#endif //TUTORIALS_SHADERLOADER_H
