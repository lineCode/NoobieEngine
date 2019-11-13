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
    MeshRenderer(const MeshDto & meshDto);
    void onRender() override;
private:
    void setupMesh(const MeshDto & meshDto);
private:
    MeshDto m_MeshDto;
    std::unique_ptr<VertexArray> m_VertexArray;
};


#endif //NOOBYENGINE_MESH_H
