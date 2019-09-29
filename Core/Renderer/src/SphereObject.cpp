//
// Created by Rob on 2019-09-25.
//

#include "SphereObject.h"


SphereObject::SphereObject() 
{
    init(48);
}

SphereObject::SphereObject(int prec) 
{
    init(prec);
}

float SphereObject::toRadians(float degrees) 
{ 
    return glm::radians(degrees);
}

void SphereObject::init(int prec) 
{
    m_numVertices = (prec + 1) * (prec + 1);
    m_numIndices = prec * prec * 6;

    for (int i = 0; i < m_numVertices; i++) 
    { 
        vertices.push_back(glm::vec3()); 
    }

    for (int i = 0; i < m_numVertices; i++) 
    {
        texCoords.push_back(glm::vec2()); 
    }

    for (int i = 0; i < m_numVertices; i++)
    {
        normals.push_back(glm::vec3()); 
    }

    for (int i = 0; i < m_numVertices; i++) 
    { 
        tangents.push_back(glm::vec3()); 
    }

    for (int i = 0; i < m_numIndices; i++) 
    { 
        indices.push_back(0); 
    }

    // calculate triangle vertices
    for (int i = 0; i <= prec; i++) 
    {
        for (int j = 0; j <= prec; j++) 
        {
            float y = (float) cos(toRadians(180.0f - i * 180.0f / prec));
            float x = -(float) cos(toRadians(j * 360.0f / prec)) * (float)abs(cos(asin(y)));
            float z = (float) sin(toRadians(j * 360.0f / (float)(prec))) * (float)abs(cos(asin(y)));
            vertices[i * (prec + 1) + j] = glm::vec3(x, y, z);
            texCoords[i * (prec + 1) + j] = glm::vec2(((float)j / prec), ((float)i / prec));
            normals[i * (prec + 1) + j] = glm::vec3(x, y, z);

            // calculate tangent vector
            if (((x == 0) && (y == 1) && (z == 0)) || ((x == 0) && (y == -1) && (z == 0))) {
                tangents[i * (prec + 1) + j] = glm::vec3(0.0f, 0.0f, -1.0f);
            }
            else {
                tangents[i * (prec + 1) + j] = glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(x, y, z));
            }
        }
    }
    // calculate triangle indices
    for (int i = 0; i < prec; i++) 
    {
        for (int j = 0; j < prec; j++) 
        {
            indices[6 * (i * prec + j) + 0] = i * (prec + 1) + j;
            indices[6 * (i * prec + j) + 1] = i * (prec + 1) + j + 1;
            indices[6 * (i * prec + j) + 2] = (i + 1) * (prec + 1) + j;
            indices[6 * (i * prec + j) + 3] = i * (prec + 1) + j + 1;
            indices[6 * (i * prec + j) + 4] = (i + 1) * (prec + 1) + j + 1;
            indices[6 * (i * prec + j) + 5] = (i + 1) * (prec + 1) + j;
        }
    }

    m_pvalues = std::make_unique<std::vector<float>>();
    m_tvalues = std::make_unique<std::vector<float>>();
    m_nvalues = std::make_unique<std::vector<float>>();
    for (int i = 0; i < m_numIndices; i++) {
        m_pvalues->push_back((vertices[indices[i]]).x);
        m_pvalues->push_back((vertices[indices[i]]).y);
        m_pvalues->push_back((vertices[indices[i]]).z);
        m_tvalues->push_back((texCoords[indices[i]]).s);
        m_tvalues->push_back((texCoords[indices[i]]).t);
        m_nvalues->push_back((normals[indices[i]]).x);
        m_nvalues->push_back((normals[indices[i]]).y);
        m_nvalues->push_back((normals[indices[i]]).z);
    }

    m_Vao = std::make_unique<VertexArray>();
    m_Vao->addBuffer(*m_pvalues, 3, GL_ARRAY_BUFFER, GL_TRIANGLES);
    m_Vao->addBuffer(*m_tvalues, 3, GL_ARRAY_BUFFER, GL_TRIANGLES);
    m_Vao->addBuffer(*m_nvalues, 3, GL_ARRAY_BUFFER, GL_TRIANGLES);
}

int SphereObject::getNumVertices() 
{ 
    return m_numVertices; 
}

int SphereObject::getNumIndices() 
{ 
    return m_numIndices; 
}

std::vector<int> SphereObject::getIndices() 
{ 
    return indices; 
}

std::vector<glm::vec3> SphereObject::getVertices() 
{ 
    return vertices; 
}

std::vector<glm::vec2> SphereObject::getTexCoords() 
{ 
    return texCoords; 
}

std::vector<glm::vec3> SphereObject::getNormals() 
{ 
    return normals; 
}

std::vector<glm::vec3> SphereObject::getTangents() 
{ 
    return tangents; 
}

void SphereObject::onRender()
{
    m_Vao->onRender();
}

void SphereObject::setTexture(std::unique_ptr<GLResource> loadedTexture, GLenum activeTextureUnit)
{
    auto buffer = m_Vao->addTexture(std::move(loadedTexture), *m_nvalues, 2, GL_ARRAY_BUFFER);
    buffer->setAttributeIndex(1);
    buffer->setActiveTextureUnit(activeTextureUnit);
}
