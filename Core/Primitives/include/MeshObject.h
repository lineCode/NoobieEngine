#ifndef MESHOBJECT_H
#define MESHOBJECT_H

#include "Interfaces/IRenderableObject.h"
#include "Interfaces/GraphicTypes.h"
#include "Renderer/include/VertexArray.h"
#include "Programs/include/BaseProgram.h"

class MeshObject : public IRenderableObject
{
public:
    MeshObject(std::shared_ptr<std::vector<MeshDto>> meshDto);
    virtual void onRender() override;
    virtual void setViewMatrix(glm::mat4 viewMatrix) override;
    virtual void setProjectionMatrix(glm::mat4 projectionMatrix) override;
    virtual void setLocation(glm::vec3 location);
    void setProgram(std::shared_ptr<BaseProgram> program);
private:
    void unpackMesh(std::shared_ptr<std::vector<MeshDto>> meshDto);

    std::unique_ptr<VertexArray> m_vao;
    std::shared_ptr<std::vector<MeshDto>> m_meshDto;
    std::shared_ptr<BaseProgram> m_program;
    std::vector<glm::vec3> m_vertices;
    glm::mat4 m_mat;
    glm::mat4 m_viewMatrix;
    glm::mat4 m_projectionMatrix;
    glm::vec3 m_location;
};

#endif // MESHOBJECT_H
