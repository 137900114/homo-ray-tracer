project(homo_core)

set(SOURCES 
    src/camera.cpp
    src/light.cpp
    src/primitive.cpp
    src/ray.cpp
    src/scene.cpp
)
add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} stb_image homo_math)
