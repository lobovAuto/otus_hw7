cmake_minimum_required(VERSION 3.7.2)

set(PROJECT_NAME vector_list_tests)

project(${PROJECT_NAME})

set(TARGET_NAME vl_unit_tests)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(
        ${CMAKE_SOURCE_DIR}/gtest
)

set(INCLUDE_DIRECTORIES
        ${CMAKE_SOURCE_DIR}/homework_6/list
        ${CMAKE_SOURCE_DIR}/homework_6/vector
        ${CMAKE_SOURCE_DIR}/homework_6/container
        ${CMAKE_SOURCE_DIR}/tests/vector_test.cpp
)

add_custom_target(CLONE_PROJECTS)


add_executable(${TARGET_NAME}
   ${CMAKE_SOURCE_DIR}/tests/vector_test.cpp
   ${CMAKE_SOURCE_DIR}/tests/list_test.cpp
)

include(${CMAKE_SOURCE_DIR}/dependencies.cmake)

target_link_libraries(${TARGET_NAME} PRIVATE
        gtest gtest_main
        gmock 
)
target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDE_DIRECTORIES})

target_compile_options(${TARGET_NAME} PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
        )