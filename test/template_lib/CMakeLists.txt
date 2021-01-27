project(template_lib_test) # TODO: Rename

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable(${PROJECT_NAME})
add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        # Copy resources to binary folder
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources

        # Copy dependencies to binary folder
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:template_lib> ${PROJECT_BINARY_DIR}/
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:gtest_main> ${PROJECT_BINARY_DIR}/
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:gtest> ${PROJECT_BINARY_DIR}/
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:gmock_main> ${PROJECT_BINARY_DIR}/
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:gmock> ${PROJECT_BINARY_DIR}/
        )

add_subdirectory(src)

target_compile_definitions(${PROJECT_NAME} PRIVATE TEMPLATE_LIB_IMPORT)
target_link_libraries(${PROJECT_NAME} PRIVATE template_lib nlohmann_json::nlohmann_json gtest gtest_main gmock gmock_main)
