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
    AssimpModelLoader() = default;
    virtual ~AssimpModelLoader() = default;
    void loadFromFile(const std::string & path) override;
private:
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<TextureDto> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
private:
    std::vector<Mesh> meshes;
};


#endif //NOOBYENGINE_ASSIMPMODELLOADER_H
