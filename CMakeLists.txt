cmake_minimum_required(VERSION 3.0)

set(project("race")) # set variable containing project name

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

include_directories(include) # include header files

add_executable(${project} src/*.cpp) # add all source files to the project