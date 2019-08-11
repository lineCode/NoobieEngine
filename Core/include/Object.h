//
// Created by Rob on 2019-07-13.
//

#ifndef Object_h
#define Object_h

#include "VertexArray.h"
#include "../Interfaces/IRenderable.h"
#include <vector>
#include <memory>

class Object : public IRenderable
{
public:
    Object(std::vector<float> vertices);
private:
    std::vector<float> m_Vertices;
    std::unique_ptr<VertexArray> m_Vao;

    // Inherited via IRenderable
    virtual void onRender() override;
};

#endif // !Object_h
