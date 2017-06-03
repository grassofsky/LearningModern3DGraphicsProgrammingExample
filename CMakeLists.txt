CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#======================================================================
# Version
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "1")
SET(CPACK_PACKAGE_VERSION_PATCH "0")

SET(CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")

#======================================================================
# Set project
PROJECT(LearningModern3DGraphicProgramming)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

#======================================================================
# Find opengl package
FIND_PACKAGE(OpenGL REQUIRED)
INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
FIND_PACKAGE(GLUT REQUIRED)
INCLUDE_DIRECTORIES(${GLUT_INCLUDE_DIR})
FIND_PACKAGE(GLEW REQUIRED)
INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIR})

#======================================================================
# Recurse to subdirectories
add_subdirectory(src)
