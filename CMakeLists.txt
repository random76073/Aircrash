cmake_minimum_required(VERSION 3.24)
project(Aircrash)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

file(GLOB_RECURSE DIR_SRCS src/*.cpp)
find_library(GLFW glfw3)

# add_library(GLC SHARED dll/GLC/GLC.cpp)
add_executable(Aircrash main.cpp ${DIR_SRCS})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(Aircrash ${GLFW})
# target_link_libraries(Aircrash GLC)
