cmake_minimum_required(VERSION 3.11)
project(OOP_indie_studio_2018 CXX)

set(dir ${CMAKE_CURRENT_SOURCE_DIR}/.)
set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-lIrrlicht -lGL -lGLU -lX11 -lXxf86vm -lXext")

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source/cmake_modules/)
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/source
        ${PROJECT_SOURCE_DIR}/tests
)
file(GLOB all_src
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/source/core/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/game/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/graphical_engine/*.cpp
        )
file(GLOB main_src
        ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
        )
file(GLOB tests_src
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp
        )

find_package(Irrlicht)
add_executable(bomberman ${main_src} ${all_src})
target_link_libraries(bomberman Irrlicht)

find_package(Criterion)
add_executable(unit-tests ${all_src} ${tests_src})
target_link_libraries(unit-tests criterion Irrlicht)
