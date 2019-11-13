//
// Created by Rob on 2019-07-21.
//

#ifndef NOOBYENGINE_MESH_H
#define NOOBYENGINE_MESH_H

#include "VertexArray.h"
#include "Interfaces/IRenderable.h"
#include "Interfaces/GraphicTypes.h"
#include <glm/glm.hpp>
#include <vector>
#include <string>

class MeshRenderer : IRenderable
{
public:
    MeshRenderer(std::unique_ptr<MeshDto> meshDto);
    void onRender() override;
private:
    void setupMesh(MeshDto * meshDto);
private:
    std::unique_ptr<MeshDto> m_MeshDto;
    std::unique_ptr<VertexArray> m_VertexArray;
};


#endif //NOOBYENGINE_MESH_H
