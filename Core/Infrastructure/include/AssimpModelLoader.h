//
// Created by Rob on 2019-07-20.
//

#ifndef NOOBYENGINE_ASSIMPMODELLOADER_H
#define NOOBYENGINE_ASSIMPMODELLOADER_H

#include "Core/Renderer/include/MeshRenderer.h"
#include "Interfaces/IModelLoader.h"
#include <assimp/scene.h>
#include <string>
#include <vector>

class AssimpModelLoader : public IModelLoader
{
public:
    AssimpModelLoader() = default;
    virtual ~AssimpModelLoader() override = default;
    std::vector<MeshDto> loadFromFile(const fs::path & path) override;
private:
    std::vector<MeshDto> processNode(aiNode *node, const aiScene *scene, const fs::path & assetDir);
    MeshDto processMesh(aiMesh *mesh, const aiScene *scene, const fs::path & assetDir);
    std::vector<TextureDto> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName, const fs::path & assetDir);
};


#endif //NOOBYENGINE_ASSIMPMODELLOADER_H
