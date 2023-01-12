cmake_minimum_required(VERSION 3.20)

project(measurements VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-std=c++20 -O3 -g -Wall -Wextra --pedantic")

add_library(${PROJECT_NAME} 
    SHARED 
        ${PROJECT_SOURCE_DIR}/include/measurements.hpp)

target_include_directories(${PROJECT_NAME} 
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

set_target_properties(${PROJECT_NAME} 
    PROPERTIES 
        LINKER_LANGUAGE CXX)

add_executable(test ${PROJECT_SOURCE_DIR}/test/main.cpp)
target_link_libraries(test PRIVATE ${PROJECT_NAME})