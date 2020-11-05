cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 17)

project(HomoRT)
add_executable(${PROJECT_NAME} main.cpp) 


add_subdirectory(math)
add_subdirectory(third_party)
add_subdirectory(core)


target_link_libraries(${PROJECT_NAME} stb_image homo_core homo_math)