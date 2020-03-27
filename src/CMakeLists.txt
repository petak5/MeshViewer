cmake_minimum_required(VERSION 3.10)
project(MeshViewer)

file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# or alternatively
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

find_package(glfw3 REQUIRED)

include_directories(dependencies/glad/include/)

file(GLOB HEADER_FILES *.h *.hpp)
file(GLOB SOURCE_FILES *.c *.cpp)
# or alternatively
#set(SOURCE_FILES main.cpp glad.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries (${PROJECT_NAME} glfw)