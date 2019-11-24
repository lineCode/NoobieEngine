//
// Created by Rob on 2019-07-13.
//

#ifndef Object_h
#define Object_h

#include "Renderer/include/VertexArray.h"

class DrawableObject : public IRenderable
{
public:
    DrawableObject(glm::vec3 location, const std::vector<float> & vertices, unsigned int numCopies);
    virtual void onRender() override;

    glm::vec3 location() const;

    void setTexture(std::unique_ptr<GLResource> loadedTexture, const std::vector<float>& textureCoordinates, GLenum activeTextureUnit);
    void setAttributeIndex(GLuint attributeLocation);
private:
    std::vector<float> m_Vertices;
    std::unique_ptr<VertexArray> m_Vao;
    glm::vec3 m_Location;
    unsigned int m_NumCopies;
    GLuint m_attributeIndex;
};

#endif // !Object_h
