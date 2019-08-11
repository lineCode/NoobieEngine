//
// Created by Rob on 2019-07-14.
//

#include "VertexBuffer.h"
#include <GL/glew.h>

VertexBuffer::VertexBuffer()
    :m_DrawMode(GL_TRIANGLES)
{

}

GLuint VertexBuffer::handle()
{
    return m_Buffer->resourceId();
}

GLuint VertexBuffer::attributeIndex()
{
    return m_AttributeIndex;
}

unsigned int VertexBuffer::count()
{
    return m_Count;
}

GLuint VertexBuffer::stride()
{
    return m_Stride;
}

GLuint VertexBuffer::drawMode()
{
    return m_DrawMode;
}