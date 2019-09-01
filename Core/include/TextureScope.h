//
// Created by Rob on 2019-08-31.
//

#ifndef NOOBYENGINE_TEXTURESCOPE_H
#define NOOBYENGINE_TEXTURESCOPE_H

#include "VertexBuffer.h"

class TextureScope
{
public:
    TextureScope(VertexBuffer * vertexBuffer);
    ~TextureScope(){}
private:
    VertexBuffer * m_VertexBuffer;
};


#endif //NOOBYENGINE_TEXTURESCOPE_H
