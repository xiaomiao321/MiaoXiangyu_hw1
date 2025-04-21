cmake_minimum_required(VERSION 3.0)  

project(main)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

set(INC_DIR ${PROJECT_SOURCE_DIR}/inc)

aux_source_directory(${SRC_DIR} SRC_LIST)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${INC_DIR})

add_executable(main ${SRC_LIST})