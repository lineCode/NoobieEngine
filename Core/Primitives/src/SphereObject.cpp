//
// Created by Rob on 2019-09-25.
//
#pragma warning( disable : 26451)

#include "SphereObject.h"
#include "Infrastructure/include/GLSafe.h"
#include "external/glm-0.9.7.1/glm/gtc/matrix_transform.hpp"
#include "external/glm-0.9.7.1/glm/gtc/matrix_transform.hpp"
#include "external/glm-0.9.7.1/glm/gtc/type_ptr.hpp"
#include "Programs/include/SphereProgram.h"

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

    m_vertices.resize(m_numVertices);
    m_texCoords.resize(m_numVertices);
    m_normals.resize(m_numVertices);
    m_tangents.resize(m_numVertices);
    m_indices.resize(m_numIndices);

    // calculate triangle vertices
    for (auto i = 0u; i <= prec; i++) 
    {
        for (auto j = 0u; j <= prec; j++) 
        {
            float y = (float) cos(toRadians(180.0f - i * 180.0f / prec));
            float x = -(float) cos(toRadians(j * 360.0f / prec)) * (float)abs(cos(asin(y)));
            float z = (float) sin(toRadians(j * 360.0f / (float)(prec))) * (float)abs(cos(asin(y)));
            auto index = i * (prec + 1u) + j;
            m_vertices[index] = glm::vec3(x, y, z);
            m_texCoords[index] = glm::vec2(((float)j / prec), ((float)i / prec));
            m_normals[index] = glm::vec3(x, y, z);

            // calculate tangent vector
            if (((x == 0) && (y == 1) && (z == 0)) || ((x == 0) && (y == -1) && (z == 0))) {
                m_tangents[index] = glm::vec3(0.0f, 0.0f, -1.0f);
            }
            else {
                m_tangents[index] = glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(x, y, z));
            }
        }
    }
    // calculate triangle indices
    for (auto i = 0u; i < prec; i++) 
    {
        for (auto j = 0u; j < prec; j++) 
        {
            auto t = 6 * (i * prec + j);
            m_indices[t + 0] = i * (prec + 1) + j;
            m_indices[t + 1] = i * (prec + 1) + j + 1;
            m_indices[t + 2] = (i + 1) * (prec + 1) + j;
            m_indices[t + 3] = i * (prec + 1) + j + 1;
            m_indices[t + 4] = (i + 1) * (prec + 1) + j + 1;
            m_indices[t + 5] = (i + 1) * (prec + 1) + j;
        }
    }

    for (int i = 0; i < m_numIndices; i++) {
        m_pvalues.push_back((m_vertices[m_indices[i]]).x);
        m_pvalues.push_back((m_vertices[m_indices[i]]).y);
        m_pvalues.push_back((m_vertices[m_indices[i]]).z);
        m_tvalues.push_back((m_texCoords[m_indices[i]]).s);
        m_tvalues.push_back((m_texCoords[m_indices[i]]).t);
        m_nvalues.push_back((m_normals[m_indices[i]]).x);
        m_nvalues.push_back((m_normals[m_indices[i]]).y);
        m_nvalues.push_back((m_normals[m_indices[i]]).z);
    }

    m_Vao = std::make_unique<VertexArray>();
    auto vb = m_Vao->addBuffer(m_tvalues, 2, GL_ARRAY_BUFFER, GL_TRIANGLES, 1, BufferMode::NoDraw);
    vb->setAttributeIndex(1);
    vb = m_Vao->addBuffer(m_nvalues, 3, GL_ARRAY_BUFFER, GL_TRIANGLES,1, BufferMode::None);
    //vb->setAttributeIndex(2);
    m_Vao->addBuffer(m_pvalues, 3, GL_ARRAY_BUFFER, GL_TRIANGLES, 1, BufferMode::SingleCopy);
    vb->setAttributeIndex(0);
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
    return m_indices;
}

const std::vector<glm::vec3>& SphereObject::vertices() 
{ 
    return m_vertices;
}

const std::vector<glm::vec2>& SphereObject::texCoords() 
{ 
    return m_texCoords; 
}

const std::vector<glm::vec3>& SphereObject::normals() 
{ 
    return m_normals; 
}

const std::vector<glm::vec3>& SphereObject::tangents() 
{ 
    return m_tangents; 
}

void SphereObject::onRender()
{
    m_mat = glm::translate(glm::mat4(1.0f), m_location);


    auto mvMat = m_viewMatrix * m_mat;
    auto sphereProgram = (SphereProgram*)m_program.get();
    GLCall(glUniformMatrix4fv(sphereProgram->modelViewMatrixLocation(), 1, GL_FALSE, glm::value_ptr(mvMat)))
    GLCall(glUniformMatrix4fv(sphereProgram->projectionMatrixLocation(), 1, GL_FALSE, glm::value_ptr(m_projectionMatrix)))
    
    m_Vao->onRender();
}

void SphereObject::setViewMatrix(glm::mat4 viewMatrix)
{
    m_viewMatrix = viewMatrix;
}

void SphereObject::setProjectionMatrix(glm::mat4 projectionMatrix)
{
    m_projectionMatrix = projectionMatrix;
}

void SphereObject::setLocation(glm::vec3 location)
{
    m_location = location;
}

void SphereObject::setProgram(std::shared_ptr<BaseProgram> program)
{
    m_program = program;
    m_program->useProgram();
}

void SphereObject::setTexture(std::unique_ptr<GLResource> loadedTexture, GLenum activeTextureUnit)
{
    GLint samplerLoc;
    auto buffer = m_Vao->addTexture(std::move(loadedTexture), m_nvalues, 2, GL_ARRAY_BUFFER);
    //buffer->setAttributeIndex(2);
    GLCall(samplerLoc = glGetUniformLocation(m_program->programId(), "samp"))
    buffer->setActiveTextureUnit(activeTextureUnit);
    buffer->setTextureUniformLocation(samplerLoc);
}