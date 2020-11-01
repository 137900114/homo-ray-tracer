project(stb_image)

add_library(${PROJECT_NAME} STATIC std_image.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
