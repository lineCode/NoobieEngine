//
// Created by Rob on 2019-07-20.
//

#ifndef NOOBYENGINE_ASSIMPMODELLOADER_H
#define NOOBYENGINE_ASSIMPMODELLOADER_H

#include "Core/Renderer/include/Mesh.h"
#include "Interfaces/IModelLoader.h"
#include <assimp/scene.h>
#include <string>
#include <vector>


class AssimpModelLoader : IModelLoader
{
public:
    void loadFromFile(const std::string & path) override;
private:
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
private:
    std::vector<Mesh> meshes;
};


#endif //NOOBYENGINE_ASSIMPMODELLOADER_H
