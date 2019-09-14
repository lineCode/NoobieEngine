//
// Created by Rob on 2019-07-13.
//

#ifndef NOOBYENGINE_ICONTEXT_H
#define NOOBYENGINE_ICONTEXT_H


class IContext {
public:
    virtual ~IContext() = default;

    virtual void *handle() = 0;
    virtual void swapBuffer() = 0;
    virtual int width() = 0;
    virtual int height() = 0;
    virtual void startContext() = 0;
    virtual void endContext() = 0;
};


#endif //NOOBYENGINE_ICONTEXT_H
