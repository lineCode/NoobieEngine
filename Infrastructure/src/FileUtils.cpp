//
// Created by Rob on 2019-07-14.
//

#include "include/FileUtils.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::string readFromFile(const std::string & fileName)
{
    std::string shaderFile;
    std::ifstream shaderStream(fileName.c_str());
    if(shaderStream.is_open())
    {
        std::stringstream sstr;
        sstr << shaderStream.rdbuf();
        shaderFile = sstr.str();
        shaderStream.close();
    } else{
        std::cerr << "Error loading shader %s", fileName.c_str();
        exit(-1);
    }

    return shaderFile;
}