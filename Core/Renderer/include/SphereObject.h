//
// Created by Rob on 2019-09-25.
//

#ifndef NOOBYENGINE_CIRCLEOBJECT_H
#define NOOBYENGINE_CIRCLEOBJECT_H

#include "VertexArray.h"

class SphereObject : public IRenderable
{

public:
    SphereObject();
    SphereObject(int prec);
    virtual void onRender() override;

    int getNumVertices();
    int getNumIndices();
    std::vector<int> getIndices();
    std::vector<glm::vec3> getVertices();
    std::vector<glm::vec2> getTexCoords();
    std::vector<glm::vec3> getNormals();
    std::vector<glm::vec3> getTangents();
    void setTexture(std::unique_ptr<GLResource> loadedTexture, GLenum activeTextureUnit);
private:
    std::unique_ptr<VertexArray> m_Vao;
    int m_numVertices;
    int m_numIndices;
    std::vector<int> indices;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> texCoords;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec3> tangents;

    std::unique_ptr<std::vector<float>> m_pvalues;
    std::unique_ptr<std::vector<float>> m_tvalues;
    std::unique_ptr<std::vector<float>> m_nvalues;

    void init(int);
    float toRadians(float degrees);
};


#endif //NOOBYENGINE_CIRCLEOBJECT_H
