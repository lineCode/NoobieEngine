//
// Created by Rob on 2019-07-09.
//

#include "include/GLResource.h"

GLResource::~GLResource() {
    m_Deleter();
}

GLuint GLResource::resourceId()
{
    return m_ResourceId;
}
