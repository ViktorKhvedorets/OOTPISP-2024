cmake_minimum_required(VERSION 3.15.0)

project(LAB_03_220224)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)



set(SOURCE_FILES  main.cpp
animal.cpp fish.cpp bird.cpp mammal.cpp reptile.cpp)

set(HEADER_FILES animal.h fish.h bird.h mammal.h reptile.h)

set(ALL_SOURCES ${HEADER_FILES}
                ${SOURCE_FILES})


add_executable(${PROJECT_NAME} ${ALL_SOURCES})