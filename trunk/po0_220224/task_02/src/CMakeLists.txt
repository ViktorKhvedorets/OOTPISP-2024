cmake_minimum_required(VERSION 3.15.0)

project(LAB_02_220224)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)



set(SOURCE_FILES  main.cpp
Document.cpp invoice.cpp receipt.cpp check.cpp)

set(HEADER_FILES Document.h invoice.h receipt.h check.h)

set(ALL_SOURCES ${HEADER_FILES}
                ${SOURCE_FILES})


add_executable(${PROJECT_NAME} ${ALL_SOURCES})