#ifndef GRAPHICTYPES_H
#define GRAPHICTYPES_H

#include <glm/glm.hpp>
#include <string>
#include <memory>
#include <vector>

struct VertexDto
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct TextureDto
{
    unsigned int id;
    std::string type;
    std::string path;
};

class MeshDto
{
public:
    std::vector<VertexDto> Vertices;
    std::vector<unsigned int> Indices;
    std::vector<TextureDto> Textures;
};

#endif // GRAPHICTYPES_H
