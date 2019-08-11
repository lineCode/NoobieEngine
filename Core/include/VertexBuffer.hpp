//
// Created by Rob on 2019-07-24.
//

#ifndef NOOBYENGINE_VERTEXBUFFER_HPP
#define NOOBYENGINE_VERTEXBUFFER_HPP

template<typename T> void VertexBuffer::makeBuffer(const std::vector<T> & vertices, GLuint bufferType, GLuint attributeIndex)
{
    m_AttributeIndex = attributeIndex;
    m_Count = static_cast<unsigned int>(vertices.size());
    m_Stride = 3;
    GLuint vertexbuffer;
    GLCall(glGenBuffers(1, &vertexbuffer))
    GLCall(glBindBuffer(bufferType, vertexbuffer))
    GLCall(glBufferData(bufferType, sizeof(T) * vertices.size(), &vertices[0], GL_STATIC_DRAW))
    m_Buffer = std::make_unique<GLResource>(vertexbuffer, [vertexbuffer]()
    {
        glDeleteBuffers(1, &vertexbuffer);
    });
}

#endif //NOOBYENGINE_VERTEXBUFFER_HPP