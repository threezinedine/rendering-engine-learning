cmake_minimum_required(VERSION 3.20)

project(RenderingEngine)

include(cmake/package.cmake)

set(CORE_DIR "${CMAKE_SOURCE_DIR}/core")
set(APP_DIR "${CMAKE_SOURCE_DIR}/application")

file(
    GLOB_RECURSE 
    CORE_SOURCE_FILES
    "${CORE_DIR}/*.cpp"
)

file(
    GLOB_RECURSE
    CORE_HEADER_FILES
    "${CORE_DIR}/*.h"
)

file(
    GLOB_RECURSE 
    APP_SOURCE_FILES
    "${APP_DIR}/*.cpp"
)

file(
    GLOB_RECURSE 
    APP_HEADER_FILES
    "${APP_DIR}/*.h"
)

add_executable(
    ${PROJECT_NAME}
    ${APP_SOURCE_FILES}
    ${APP_HEADER_FILES}
    ${CORE_SOURCE_FILES}
    ${CORE_HEADER_FILES}
)

add_package(
    PACKAGE glfw 
    URL     https://github.com/glfw/glfw.git
)

add_package(
    PACKAGE glm  
    URL     https://github.com/g-truc/glm.git
)

add_package(
    PACKAGE nlohmann_json
    URL     https://github.com/nlohmann/json.git
)

add_package(
    PACKAGE tinygltf
    URL     https://github.com/syoyo/tinygltf.git
    BRANCH  release
)

add_package(
    PACKAGE spdlog
    URL     https://github.com/gabime/spdlog.git
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    glfw
    glm
    nlohmann_json
    tinygltf
    spdlog
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${CORE_DIR}
    ${APP_DIR}
)