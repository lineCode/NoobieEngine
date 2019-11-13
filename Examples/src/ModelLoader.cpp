//
// Created by Rob on 2019-09-29.
//

#include "../../Infrastructure/include/AssimpModelLoader.h"

int main()
{
    std::unique_ptr<IModelLoader> loader = std::make_unique<AssimpModelLoader>();
    loader->loadFromFile("monkey.obj");
}
