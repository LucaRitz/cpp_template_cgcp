cmake_minimum_required(VERSION 3.15.1)
project(main)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(ext)
set(BUILD_SHARED_LIBS ON CACHE INTERNAL "")
find_package(OpenCV REQUIRED CONFIG
        PATHS ${CMAKE_BINARY_DIR}/ext/opencv/opencv)
unset(BUILD_SHARED_LIBS)

add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(test)
add_subdirectory(doc_source)
add_subdirectory(doxygen)