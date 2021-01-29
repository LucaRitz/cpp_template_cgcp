
add_custom_target(doxygen
        COMMAND docker-compose up
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doxygen)