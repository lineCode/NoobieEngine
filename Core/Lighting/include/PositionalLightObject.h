#pragma once

#include "Interfaces/IRenderableObject.h"
#include "Programs/include/BaseProgram.h"
#include "Renderer/include/VertexArray.h"
#include "Interfaces/GraphicTypes.h"
#include "Primitives/include/MeshObject.h"

class PositionalLightObject : public IRenderableObject
{
public:
    PositionalLightObject(std::shared_ptr<MeshObject> lightSourceModel);
    virtual void onRender() override;
    virtual void setViewMatrix(glm::mat4 viewMatrix) override;
    virtual void setProjectionMatrix(glm::mat4 projectionMatrix) override;
    void setProgram(std::shared_ptr<BaseProgram> program);
    void setLocation(glm::vec3 location);
private:
    std::shared_ptr<MeshObject> m_lightSourceModel;
    std::shared_ptr<BaseProgram> m_program;
    std::unique_ptr<VertexArray> m_vao;
    glm::mat4 m_mat;
    glm::mat4 m_viewMatrix;
    glm::vec3 m_location;
    glm::mat4 m_projectionMatrix;
    GLuint m_globalAmbLoc;
    GLuint m_ambLoc;
    GLuint m_diffLoc;
    GLuint m_specLoc;
    GLuint m_posLoc;
};