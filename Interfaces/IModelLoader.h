//
// Created by Rob on 2019-07-20.
//

#ifndef NOOBYENGINE_IMODELLOADER_H
#define NOOBYENGINE_IMODELLOADER_H

#include "GraphicTypes.h"
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

class IModelLoader
{
public:
    virtual std::vector<MeshDto> loadFromFile(const fs::path & fileName) = 0;
    virtual ~IModelLoader() {}
};

#endif //NOOBYENGINE_IMODELLOADER_H
