//
// Created by Rob on 2019-07-13.
//

#ifndef Object_h
#define Object_h

#include "VertexArray.h"


class DrawableObject : public IRenderable
{
public:
    DrawableObject(glm::vec3 location, std::vector<float> vertices, unsigned int numCopies);
    glm::vec3 location();
    virtual void onRender() override;
private:
    std::vector<float> m_Vertices;
    std::unique_ptr<VertexArray> m_Vao;
    glm::vec3 m_Location;
    unsigned int m_NumCopies;
};

#endif // !Object_h
