//
// Created by Rob on 2019-08-27.
//

#ifndef NOOBYENGINE_ISHADERLOADER_H
#define NOOBYENGINE_ISHADERLOADER_H

#include "ShaderFileInfo.h"
#include "include/GLResource.h"
#include <vector>
#include <memory>

class IShaderLoader
{
public:
    virtual std::unique_ptr<GLResource> createProgram(std::initializer_list<ShaderFileInfo> shaderInfoList) = 0;
};

#endif //NOOBYENGINE_ISHADERLOADER_H
