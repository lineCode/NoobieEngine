//
// Created by Rob on 2019-08-27.
//

#ifndef NOOBYENGINE_SHADERFILEINFO_H
#define NOOBYENGINE_SHADERFILEINFO_H

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

#endif //NOOBYENGINE_SHADERFILEINFO_H
