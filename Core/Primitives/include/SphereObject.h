//
// Created by Rob on 2019-09-25.
//

#ifndef NOOBYENGINE_CIRCLEOBJECT_H
#define NOOBYENGINE_CIRCLEOBJECT_H

#include "Interfaces/IRenderableObject.h"
#include "Renderer/include/VertexArray.h"
#include "Programs/include/BaseProgram.h"

class SphereObject : public IRenderableObject
{

public:
    SphereObject();
    SphereObject(uint32_t prec);
    virtual void onRender() override;
    virtual void setViewMatrix(glm::mat4 viewMatrix) override;
    virtual void setProjectionMatrix(glm::mat4 projectionMatrix) override;

    int numVertices();
    int numIndices();
    const std::vector<int>& indices();
    const std::vector<glm::vec3>& vertices();
    const std::vector<glm::vec2>& texCoords();
    const std::vector<glm::vec3>& normals();
    const std::vector<glm::vec3>& tangents();
    //potential methods to abstract
    void setTexture(std::unique_ptr<GLResource> loadedTexture, GLenum activeTextureUnit);
    void init(uint32_t);
    void setProgram(std::shared_ptr<BaseProgram> program);
    void setLocation(glm::vec3 location);
private:
    std::unique_ptr<VertexArray> m_Vao;
    int m_numVertices;
    int m_numIndices;
    std::unique_ptr<std::vector<int>> m_indices;
    std::unique_ptr<std::vector<glm::vec3>> m_vertices;
    std::unique_ptr<std::vector<glm::vec2>> m_texCoords;
    std::unique_ptr<std::vector<glm::vec3>> m_normals;
    std::unique_ptr<std::vector<glm::vec3>> m_tangents;

    std::unique_ptr<std::vector<float>> m_pvalues;
    std::unique_ptr<std::vector<float>> m_tvalues;
    std::unique_ptr<std::vector<float>> m_nvalues;
    std::shared_ptr<BaseProgram> m_program;
    glm::mat4 m_mat;
    glm::mat4 m_viewMatrix;
    glm::mat4 m_projectionMatrix;
    float toRadians(float degrees);
    glm::vec3 m_location;
};


#endif //NOOBYENGINE_CIRCLEOBJECT_H
