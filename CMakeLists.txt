cmake_minimum_required(VERSION 3.20)

project(pong)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/*.h" "${PROJECT_SOURCE_DIR}/src/*.c")


find_package(OpenGL REQUIRED)
add_executable(pong ${SOURCES})
target_include_directories(pong PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_link_directories(pong PRIVATE
    "${CMAKE_SOURCE_DIR}/lib/"
)

target_link_libraries(pong PRIVATE ${OPENGL_LIBRARIES})
target_link_libraries(pong PRIVATE OpenGL::GL glfw3)
