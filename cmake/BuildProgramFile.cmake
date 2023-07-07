option(PATH_VAR_NAME "is this argument optional?" DEFINED)
if(DEFINED PATH_VAR_NAME)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/program/program.cpp
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/external/program_file_generator/program_file_generator
        COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/external/program_file_generator/program_file_generator
    )
    add_executable(program_file_generator external/program_file_generator/program_file_generator.cpp)
    target_compile_options(program_file_generator PUBLIC -DPATH=${PATH_VAR_NAME})
    
endif()