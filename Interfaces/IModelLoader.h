//
// Created by Rob on 2019-07-20.
//

#ifndef NOOBYENGINE_IMODELLOADER_H
#define NOOBYENGINE_IMODELLOADER_H

class IModelLoader
{
public:
    virtual void loadFromFile(const std::string & fileName) = 0;
};

#endif //NOOBYENGINE_IMODELLOADER_H
