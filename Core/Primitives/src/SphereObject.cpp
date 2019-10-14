//
// Created by Rob on 2019-09-25.
//
#pragma warning( disable : 26451)

#include "SphereObject.h"


SphereObject::SphereObject() 
{
    init(48);
}

SphereObject::SphereObject(uint32_t prec)
{
    init(prec);
}

float SphereObject::toRadians(float degrees) 
{ 
    return glm::radians(degrees);
}

void SphereObject::init(uint32_t prec) 
{
    m_numVertices = (prec + 1) * (prec + 1);
    m_numIndices = prec * prec * 6;

    m_vertices = std::make_unique<std::vector<glm::vec3>>(m_numVertices);
    m_texCoords = std::make_unique<std::vector<glm::vec2>>(m_numVertices);
    m_normals = std::make_unique<std::vector<glm::vec3>>(m_numVertices);
    m_tangents = std::make_unique<std::vector<glm::vec3>>(m_numVertices);
    m_indices = std::make_unique<std::vector<int>>(m_numIndices);

    // calculate triangle vertices
    for (auto i = 0u; i <= prec; i++) 
    {
        for (auto j = 0u; j <= prec; j++) 
        {
            float y = (float) cos(toRadians(180.0f - i * 180.0f / prec));
            float x = -(float) cos(toRadians(j * 360.0f / prec)) * (float)abs(cos(asin(y)));
            float z = (float) sin(toRadians(j * 360.0f / (float)(prec))) * (float)abs(cos(asin(y)));
            auto index = i * (prec + 1u) + j;
            (*m_vertices)[index] = glm::vec3(x, y, z);
            (*m_texCoords)[index] = glm::vec2(((float)j / prec), ((float)i / prec));
            (*m_normals)[index] = glm::vec3(x, y, z);

            // calculate tangent vector
            if (((x == 0) && (y == 1) && (z == 0)) || ((x == 0) && (y == -1) && (z == 0))) {
                (*m_tangents)[index] = glm::vec3(0.0f, 0.0f, -1.0f);
            }
            else {
                (*m_tangents)[index] = glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(x, y, z));
            }
        }
    }
    // calculate triangle indices
    for (auto i = 0u; i < prec; i++) 
    {
        for (auto j = 0u; j < prec; j++) 
        {
            auto indices = *m_indices;
            auto t = 6 * (i * prec + j);
            indices[t + 0] = i * (prec + 1) + j;
            indices[t + 1] = i * (prec + 1) + j + 1;
            indices[t + 2] = (i + 1) * (prec + 1) + j;
            indices[t + 3] = i * (prec + 1) + j + 1;
            indices[t + 4] = (i + 1) * (prec + 1) + j + 1;
            indices[t + 5] = (i + 1) * (prec + 1) + j;
        }
    }

    m_pvalues = std::make_unique<std::vector<float>>(m_numIndices);
    m_tvalues = std::make_unique<std::vector<float>>(m_numIndices);
    m_nvalues = std::make_unique<std::vector<float>>(m_numIndices);
    for (int i = 0; i < m_numIndices; i++) {
        auto indices = *m_indices;
        auto vertices = *m_vertices;
        auto texCoords = *m_texCoords;
        auto normals = *m_normals;
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

int SphereObject::numVertices() 
{ 
    return m_numVertices; 
}

int SphereObject::numIndices() 
{ 
    return m_numIndices; 
}

const std::vector<int>& SphereObject::indices() 
{ 
    return *m_indices;
}

const std::vector<glm::vec3>& SphereObject::vertices() 
{ 
    return *m_vertices;
}

const std::vector<glm::vec2>& SphereObject::texCoords() 
{ 
    return *m_texCoords; 
}

const std::vector<glm::vec3>& SphereObject::normals() 
{ 
    return *m_normals; 
}

const std::vector<glm::vec3>& SphereObject::tangents() 
{ 
    return *m_tangents; 
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

void SphereObject::setProgram(std::shared_ptr<BaseProgram> program)
{
    m_program = program;
    m_program->useProgram();
}
