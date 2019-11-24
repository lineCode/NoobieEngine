#include "MeshProgram.h"

MeshProgram::MeshProgram(std::shared_ptr<GLResource> program)
    :BaseProgram(program)
{

}

GLint MeshProgram::projectionMatrixLocation()
{
    GLint projLoc;
    GLCall(projLoc = glGetUniformLocation(m_program->resourceId(), "proj_matrix"))
    return projLoc;
}

GLint MeshProgram::modelViewMatrixLocation()
{
    GLint mvLoc;
    GLCall(mvLoc = glGetUniformLocation(m_program->resourceId(), "mv_matrix"))
    return mvLoc;
}

