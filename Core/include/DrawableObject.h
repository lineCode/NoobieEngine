//
// Created by Rob on 2019-07-13.
//

#ifndef Object_h
#define Object_h

#include "VertexArray.h"


class DrawableObject : public IRenderable
{
public:
    explicit DrawableObject(std::vector<float> vertices);
    virtual void onRender() override;
private:
    std::vector<float> m_Vertices;
    std::unique_ptr<VertexArray> m_Vao;

};

#endif // !Object_h
