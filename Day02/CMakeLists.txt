cmake_minimum_required(VERSION 3.10)

project(Day02)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

add_executable(Day02 main.cpp)

add_custom_command(TARGET Day02 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_SOURCE_DIR}/input.txt
    $<TARGET_FILE_DIR:Day02>/input.txt)
