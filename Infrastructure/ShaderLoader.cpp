//
// Created by Rob on 2019-06-29.
//

#include "ShaderLoader.h"
#include "Core/GLResource.h"
#include "Core/GLUtils.h"
#include "Infrastructure/FileUtils.h"
#include "Core/GLSafe.h"

void compileSource(const std::string & source, unsigned int shaderId);
void linkProgram(unsigned int programId, unsigned int shaderId);
void cleanBuild(unsigned int programId, std::vector<GLuint> shaders);

std::unique_ptr<GLResource> createShaderProgram(std::initializer_list<ShaderFileInfo> shaderInfoList)
{
    auto programId = glCreateProgram();
    auto program = std::make_unique<GLResource>(programId, [programId] ()
                                                            {
                                                                glDeleteProgram(programId);
                                                            });
    std::vector<GLuint> shaders;
    for(auto shaderInfo : shaderInfoList)
    {
        auto fileContents = readFromFile(shaderInfo.fileName());
        auto shaderId = glCreateShader(shaderInfo.shaderType());
        compileSource(fileContents, shaderId);
        linkProgram(programId, shaderId);
        shaders.push_back(shaderId);
    }

    cleanBuild(programId, shaders);
    return program;
}

void cleanBuild(unsigned int programId, std::vector<GLuint> shaders)
{
    for(auto shader : shaders)
    {
        GLCall(glDetachShader(programId, shader));
        GLCall(glDeleteShader(shader));
    }
}

void linkProgram(unsigned int programId, unsigned int shaderId)
{
    glAttachShader(programId, shaderId);
    glLinkProgram(programId);
    checkLinkerResult(programId);
}

void compileSource(const std::string & source, unsigned int shaderId)
{
    const char * src = source.c_str();
    glShaderSource(shaderId, 1, &src , nullptr);
    glCompileShader(shaderId);
    checkCompilationResult(shaderId);
}