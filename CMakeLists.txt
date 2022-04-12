cmake_minimum_required(VERSION 3.15.1)
project(main) # TODO: Rename the project

set(CMAKE_CXX_STANDARD 17)

# TODO: May delete these options if the project is not a pure library-project or rename them with the correct prefix otherwise.
OPTION(ANY_PREFIX_BUILD_TEST "Build tests" ON)
OPTION(ANY_PREFIX_BUILD_DOCUMENTATION "Build documentation" ON)
OPTION(ANY_PREFIX_BUILD_CODE_DOCUMENTATION "Build code documentation" ON)
OPTION(ANY_PREFIX_BUILD_EXT_LIBS "Build external libraries" ON)

if (ANY_PREFIX_BUILD_EXT_LIBS)
    message(STATUS "template-lib -- Build external dependencies")
    include(ext/externals.cmake)
else ()
    message(STATUS "template-lib -- External dependencies were not build")
endif ()

add_subdirectory(lib)

add_subdirectory(app) # TODO: May delete "app" if this project is a pure library-project -> use tests to test the lib instead

if (ANY_PREFIX_BUILD_TEST)
    message(STATUS "template-lib -- Build tests")
    add_subdirectory(test)
else()
    message(STATUS "template-lib -- Tests were not build")
endif()

if (ANY_PREFIX_BUILD_DOCUMENTATION)
    message(STATUS "template-lib -- Build documentation")
    add_subdirectory(doc_source)
else()
    message(STATUS "template-lib -- Documentation is not build")
endif()

if (ANY_PREFIX_BUILD_CODE_DOCUMENTATION)
    message(STATUS "template-lib -- Build code documentation")
    add_subdirectory(doxygen)
else()
    message(STATUS "template-lib -- Cod documentation is not build")
endif()
