cmake_minimum_required(VERSION 3.0) # minimum version of cmake required

set(project "race") # set variable containing project name
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src") # set variable containing source directory
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/inc") # set variable containing include directory
set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build") # set variable containing build directory

project(${project}) # project name

if (CMAKE_VERSION GREATER "3.0.0")
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if (CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()
endif()

include_directories(${INCLUDE_DIR}) 

#get all files except main.cpp
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")
list(REMOVE_ITEM SOURCES "${SOURCE_DIR}/main.cpp")

add_library(${project}_lib ${SOURCES})

add_executable(${project} src/main.cpp)

target_link_libraries(${project} ${project}_lib)

set_target_properties(${project}_lib PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/lib)
set_target_properties(${project} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})