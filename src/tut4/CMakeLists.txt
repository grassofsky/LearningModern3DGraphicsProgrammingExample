ADD_EXECUTABLE(manual_perspective manual_perspective.cpp)
TARGET_LINK_LIBRARIES(manual_perspective ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES})
