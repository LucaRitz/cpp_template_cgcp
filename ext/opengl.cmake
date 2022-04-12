project(opengl LANGUAGES CXX)

find_package(OpenGL REQUIRED)

add_library(opengl INTERFACE)

if (WIN32)
    target_link_libraries (opengl INTERFACE opengl32)
elseif(UNIX)
    target_link_libraries (opengl INTERFACE GL)
endif()