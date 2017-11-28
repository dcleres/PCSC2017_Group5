cmake_minimum_required(VERSION 3.8)
project(PCSC2017_Group5)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp super_cool_class.h readFile.h readFile.cpp AbstractNumericalApproximation.h AbstractNumericalApproximation.cpp LeastSquares.cpp LeastSquares.h)

find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the HTML based API
documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if(BUILD_DOCUMENTATION)
    if(NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    message("Doxygen build started.")

    add_custom_target(doc ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_in}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)

    #install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION doc)

endif()

add_executable(PCSC2017_Group5 ${SOURCE_FILES} super_cool_class.h readFile.h readFile.cpp AbstractNumericalApproximation.h AbstractNumericalApproximation.cpp LeastSquares.cpp LeastSquares.h)