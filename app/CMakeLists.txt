project(app) # TODO: Rename

add_executable(${PROJECT_NAME})

add_custom_command(TARGET ${PROJECT_NAME}
        PRE_BUILD

        # Copy resources to binary folder
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/resources/ ${PROJECT_BINARY_DIR}/resources/
        )

add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD

        # Copy dependencies to binary folder
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:template_lib> ${PROJECT_BINARY_DIR}/
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:fltk_SHARED> ${PROJECT_BINARY_DIR}/
        )
foreach(OpenCV_LIB ${OpenCV_LIBS})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E echo "Copy $<TARGET_FILE:${OpenCV_LIB}> to $<TARGET_FILE_DIR:${PROJECT_NAME}>"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${OpenCV_LIB}> $<TARGET_FILE_DIR:${PROJECT_NAME}>
            )
endforeach()

add_subdirectory(src)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        TEMPLATE_LIB_IMPORT)
target_link_libraries(${PROJECT_NAME} PRIVATE template_lib fltk_SHARED)