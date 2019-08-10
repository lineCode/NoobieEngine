//
// Created by Rob on 2019-06-29.
//

#ifndef TUTORIALS_SHADERLOADER_H
#define TUTORIALS_SHADERLOADER_H

#include "../Infrastructure/GLResource.h"
#include <vector>
#include <memory>
#include <string>

class ShaderFileInfo
{
public:
    ShaderFileInfo(std::string fileName, unsigned int shaderType) : m_FileName(fileName), m_ShaderType(shaderType)
    {

    }

    std::string fileName() {return m_FileName;}
    unsigned int shaderType() {return m_ShaderType;}
private:
    std::string m_FileName;
    unsigned int m_ShaderType;
};

std::unique_ptr<GLResource> createShaderProgram(std::initializer_list<ShaderFileInfo> shaderInfoList);

#endif //TUTORIALS_SHADERLOADER_H
