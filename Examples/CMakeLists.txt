

include_directories("../")
include_directories("../Interfaces")

configure_file(SimpleTransform.vertexshader "${CMAKE_BINARY_DIR}" COPYONLY)
configure_file(SingleColor.fragmentshader "${CMAKE_BINARY_DIR}" COPYONLY)
configure_file(MatrixUtil.glsl "${CMAKE_BINARY_DIR}" COPYONLY)
configure_file(vertShader.glsl "${CMAKE_BINARY_DIR}" COPYONLY)
configure_file(fragShader.glsl "${CMAKE_BINARY_DIR}" COPYONLY)

FILE(COPY images/brick1.jpg DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY images/earth.jpg DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY models/monkey.obj DESTINATION "${CMAKE_BINARY_DIR}")