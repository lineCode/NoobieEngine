//
// Created by Rob on 2019-09-29.
//

#include "../../Infrastructure/include/AssimpModelLoader.h"

int main()
{
    AssimpModelLoader loader;
    loader.loadFromFile("monkey.obj");
}