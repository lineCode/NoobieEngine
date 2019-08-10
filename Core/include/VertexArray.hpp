//
// Created by Rob on 2019-07-24.
//

#ifndef NOOBYENGINE_VERTEXARRAY_HPP
#define NOOBYENGINE_VERTEXARRAY_HPP

template<typename T> void VertexArray::addBuffer(const T & buffer, GLuint bufferType)
{
    auto vbo = std::make_unique<VertexBuffer>();
    vbo->makeBuffer(buffer, bufferType, m_Atrib++);
    m_VertexBuffer.push_back(std::move(vbo));
}

#endif //NOOBYENGINE_VERTEXARRAY_HPP
