cmake_minimum_required(VERSION 3.10)
project(nbody-sim)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

include_directories(${INCLUDE_DIR})

# Main source files
set(MAIN_SOURCE_FILES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/glad.c
    ${SRC_DIR}/renderer.cpp
    ${SRC_DIR}/simulator.cpp
)

# GLFW
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW3 REQUIRED glfw3)

# GLM
find_package(glm REQUIRED)

add_executable(${PROJECT_NAME} ${MAIN_SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${GLFW3_INCLUDE_DIRS}
    ${glm_INCLUDE_DIRS}
    ${INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${GLFW3_LIBRARIES}
    GLU
    GL
    dl
)

add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Build and run nbody-sim"
)

