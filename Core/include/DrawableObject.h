//
// Created by Rob on 2019-07-13.
//

#ifndef Object_h
#define Object_h

#include "VertexArray.h"
#include "Texture.h"

class DrawableObject : public IRenderable
{
public:
    DrawableObject(glm::vec3 location, const std::vector<float> & vertices, unsigned int numCopies);
    DrawableObject(glm::vec3 location, const std::vector<float> & vertices, const std::vector<float> & textureCoor, unsigned int numCopies);
    glm::vec3 location();
    virtual void onRender() override;

    void setActiveTextureUnit(GLenum textureUnit);
    void setAttributeIndex(GLuint attributeLocation);
private:
    std::vector<float> m_Vertices;
    std::unique_ptr<Texture> m_Texture;
    std::unique_ptr<VertexArray> m_Vao;
    glm::vec3 m_Location;
    unsigned int m_NumCopies;
    GLuint m_attributeIndex;
    GLenum m_activeTextureUnit;
};

#endif // !Object_h
