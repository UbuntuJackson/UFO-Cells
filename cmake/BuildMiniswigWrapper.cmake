option(GENERATE_WRAPPER "Build miniswig and generate the wrapper" OFF)
if(GENERATE_WRAPPER)
  add_subdirectory(external/miniswig)
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/scripting/wrapper.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/scripting/wrapper.h
    COMMAND cd ${CMAKE_CURRENT_SOURCE_DIR} && ${CMAKE_CXX_COMPILER}
    ARGS -x "c++" -E -CC -DSCRIPTING_API src/scripting/api.h -o ${CMAKE_CURRENT_BINARY_DIR}/miniswig.tmp -I${CMAKE_CURRENT_SOURCE_DIR}/src
    COMMAND external/miniswig/miniswig
    ARGS --input miniswig.tmp
    --output-cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/scripting/wrapper.cpp
    --output-hpp ${CMAKE_CURRENT_SOURCE_DIR}/src/scripting/wrapper.h
    --module ufo --select-namespace UfoAPI
    --output-hpp-include scripting/wrapper.h
    --input-hpp scripting/api.h
    DEPENDS external/miniswig
    IMPLICIT_DEPENDS CXX ${CMAKE_CURRENT_SOURCE_DIR}/src/scripting/api.h
    )
  add_custom_target(squirrel_wrapper ALL
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/scripting/wrapper.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/scripting/wrapper.h
  )
endif()

# EOF #
