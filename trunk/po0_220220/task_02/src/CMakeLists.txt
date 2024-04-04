cmake_minimum_required(VERSION 3.15.0)

project(LAB_02_220220)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)



set(SOURCE_FILES  main.cpp
PrintPublication.cpp Journal.cpp Book.cpp Textbook.cpp)

set(HEADER_FILES PrintPublication.h Journal.h Book.h Textbook.h)

set(ALL_SOURCES ${HEADER_FILES}
                ${SOURCE_FILES})


add_executable(${PROJECT_NAME} ${ALL_SOURCES})
