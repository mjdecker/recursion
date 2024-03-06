##
# @file CMakeLists.txt
#
# Build system for inheritance lab.
#
# @author Michael J. Decker
# @date 3/11/2024

cmake_minimum_required(VERSION 3.6)
project(inheritance)

enable_testing()
add_definitions(-std=c++11)

add_executable(factorial basics/factorial.cpp)
add_test(NAME factorial COMMAND $<TARGET_FILE:factorial>)

add_executable(practice basics/practice.cpp)
add_test(NAME practice COMMAND $<TARGET_FILE:practice>)

add_executable(additional_practice more_practice/additional_practice.cpp)
add_test(NAME additional_practice COMMAND $<TARGET_FILE:additional_practice>)

add_executable(standard_output debug_output/standard_output.cpp)
add_test(NAME standard_output COMMAND $<TARGET_FILE:standard_output>)

add_executable(standard_error debug_output/standard_error.cpp)
add_test(NAME standard_error COMMAND $<TARGET_FILE:standard_error>)

add_executable(towers debug_output/towers.cpp)
add_test(NAME towers COMMAND $<TARGET_FILE:towers>)

add_executable(towers_visualize debug_output/towers_visualize.cpp)
add_test(NAME towers_visualize COMMAND $<TARGET_FILE:towers_visualize>)

add_executable(towers_iterative debug_output/towers_iterative.cpp)
add_test(NAME towers_iterative COMMAND $<TARGET_FILE:towers_iterative>)

add_executable(pop_growth debugging/pop_growth.cpp)
add_test(NAME pop_growth COMMAND $<TARGET_FILE:pop_growth>)
