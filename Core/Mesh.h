//
// Created by Rob on 2019-07-21.
//

#ifndef NOOBYENGINE_MESH_H
#define NOOBYENGINE_MESH_H

#include <vector>
#include <glm/glm.hpp>
#include <string>
#include "Core/VertexArray.h"
#include "Interfaces/IRenderable.h"

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture
{
    unsigned int id;
    std::string type;
};

class Mesh : IRenderable
{
public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
private:
    void setupMesh(const std::vector<Vertex> & vertices, std::vector<unsigned int> indices);
    void onRender() override;
private:
    std::vector<Vertex> m_Vertices;
    std::vector<unsigned int> m_Indices;
    std::vector<Texture> m_Textures;
    std::unique_ptr<VertexArray> m_VertexArray;
};


#endif //NOOBYENGINE_MESH_H
