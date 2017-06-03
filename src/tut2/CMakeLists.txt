
ADD_EXECUTABLE(vertex_color vertex_color.cpp)
TARGET_LINK_LIBRARIES(vertex_color ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES})

ADD_EXECUTABLE(frag_position_color frag_position_color.cpp)
TARGET_LINK_LIBRARIES(frag_position_color ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES})
