cmake_minimum_required(VERSION 2.8)

project(python_tbb)

find_package(PythonLibs)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/pybind11)

pybind11_add_module(${PROJECT_NAME} "src/backend.cpp")
target_include_directories(${PROJECT_NAME} PRIVATE ${PYTHON_INCLUDE_DIRS})

