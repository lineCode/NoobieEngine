//
// Created by Rob on 2019-07-14.
//

#ifndef NOOBYENGINE_VERTEXBUFFER_H
#define NOOBYENGINE_VERTEXBUFFER_H

#include "VertexBufferBase.h"
#include "../../../Interfaces/IRenderable.h"
#include "../../Infrastructure/include/GLSafe.h"
#include <glm/glm.hpp>
#include <vector>
#include <memory>


class VertexBuffer : public VertexBufferBase 
{
public:
    VertexBuffer() = default;
    template<typename T> void makeBuffer(
        const std::vector<T> & vertices,
        unsigned int elementsPerComponent,
        GLenum bufferType);
    template<typename T> void makeBuffer(
        const std::vector<T> & vertices,
        unsigned int elementsPerComponent,
        GLenum bufferType,
        BufferMode bufferMode);
    template<typename T> void makeTexture(
        std::unique_ptr<GLResource> loadedTexture,
        const std::vector<T> & textureCoordinates,
        unsigned int elementsPerComponent,
        GLenum bufferType);

    void onRender() override;
private:
    void drawArrays();
};

#include "VertexBuffer.hpp"

#endif //NOOBYENGINE_VERTEXBUFFER_H
