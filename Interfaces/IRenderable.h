//
// Created by Rob on 2019-07-22.
//

#ifndef NOOBYENGINE_IRENDERABLE_H
#define NOOBYENGINE_IRENDERABLE_H

class IRenderable
{
public:
    virtual void onRender() = 0;
    virtual ~IRenderable() {}
};
#endif //NOOBYENGINE_IRENDERABLE_H
