option(PATH_VAR_NAME "is this argument optional?" DEFINED)
if(DEFINED PATH_VAR_NAME)
    add_custom_command(
        OUTPUT src/program/program.cpp src/program/program.h
        COMMAND g++ external/program_file_generator/program_file_generator -DOUTPUT_FILE=${PATH_VAR_NAME}
        COMMAND ./program_file_generator
    )
endif()