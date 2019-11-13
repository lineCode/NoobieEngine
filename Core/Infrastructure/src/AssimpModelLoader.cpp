//
// Created by Rob on 2019-07-20.
//

#include "include/AssimpModelLoader.h"
#include "include/FileTextureLoader.h"
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <iostream>

std::shared_ptr<std::vector<MeshDto>> AssimpModelLoader::loadFromFile(const fs::path & path)
{
    Assimp::Importer import;
    const aiScene *scene = import.ReadFile(path.string(), aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
        return std::make_shared<std::vector<MeshDto>>();
    }

    m_meshes = std::make_shared<std::vector<MeshDto>>();

    return processNode(scene->mRootNode, scene, path);
}

std::shared_ptr<std::vector<MeshDto>> AssimpModelLoader::processNode(aiNode *node, const aiScene *scene, const fs::path & assetDir)
{
    // process all the node's meshes (if any)
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        m_meshes->push_back(processMesh(mesh, scene, assetDir));
    }
    // then do the same for each of its children
    for(unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene, assetDir);
    }

    return m_meshes;
}

MeshDto AssimpModelLoader::processMesh(aiMesh *mesh, const aiScene *scene, const fs::path & assetDir)
{
    MeshDto meshDto;

    for(unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        VertexDto vertex;
        glm::vec3 vector;
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;

        glm::vec3 normal;
        normal.x = mesh->mNormals[i].x;
        normal.y = mesh->mNormals[i].y;
        normal.z = mesh->mNormals[i].z;

        //can be up to 8 tex coordinates, process the first
        if(mesh->mTextureCoords[0])
        {
            glm::vec2 vec;
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.TexCoords = vec;
        }
        else
        {
            vertex.TexCoords = glm::vec2(0.0f, 0.0f);
        }

        vertex.Position = vector;
        vertex.Normal = normal;
        meshDto.Vertices.push_back(vertex);
    }

    for(unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++)
            meshDto.Indices.push_back(face.mIndices[j]);
    }

    if(mesh->mMaterialIndex > 0)
    {
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
        auto diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse", assetDir);
        meshDto.Textures.insert(meshDto.Textures.end(), diffuseMaps.begin(), diffuseMaps.end());
        auto specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular", assetDir);
        meshDto.Textures.insert(meshDto.Textures.end(), specularMaps.begin(), specularMaps.end());
    }

    return meshDto;
}

std::vector<TextureDto> AssimpModelLoader::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName, const fs::path & assetDir)
{
    std::vector<TextureDto> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        TextureDto texture;
        //todo: should actually store the resource pointer
        texture.id = FileTextureLoader::loadTexture(assetDir.parent_path().string())->resourceId();
        texture.type = typeName;
        texture.path = str.C_Str();
        textures.push_back(texture);
    }
    return textures;
}
