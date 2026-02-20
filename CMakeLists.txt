cmake_minimum_required(VERSION 3.20)

project(RenderingEngine)

include(cmake/package.cmake)

file(
    GLOB_RECURSE 
    SOURCE_FILES
    "src/*.cpp"
)

file(
    GLOB_RECURSE 
    HEADER_FILES
    "src/*.h"
)

add_executable(
    ${PROJECT_NAME}
    ${SOURCE_FILES}
    ${HEADER_FILES}
)

# add_package(googletest https://github.com/google/googletest.git)
add_package(glfw https://github.com/glfw/glfw.git)
add_package(glm https://github.com/g-truc/glm.git)
add_package(nlohmann_json https://github.com/nlohmann/json.git)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    glfw
    glm
    nlohmann_json
)