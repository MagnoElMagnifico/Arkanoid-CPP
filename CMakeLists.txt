# This CMake program will create a Makefile to build Arkanoid
# All it does is link with SFML (which should be "installed" in the libraries
# folder) and add the Arkanoid's files into and executable.
# By Magno El Magnifico

cmake_minimum_required(VERSION 3.18.4)

project(Arkanoid)

# Source files
set(SOURCE "source/main.cpp")
set(HEADER_FILES "include")

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADER_FILES})

# Add SFML library dinamicly
set(SFML_DIR "libraries/SFML/lib/cmake/SFML")
find_package(SFML COMPONENTS "graphics" "window" "system")

if (SFML_FOUND)
    target_link_directories    (${PROJECT_NAME} PRIVATE libraries/SFML/lib)
    target_include_directories (${PROJECT_NAME} PRIVATE libraries/SFML/include)
    target_link_libraries      (${PROJECT_NAME} sfml-graphics)
else()
    message(FATAL_ERROR "--* SFML Modules not found")
endif()
