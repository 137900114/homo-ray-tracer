project(homo_core)

set(SHAPE_SOURCES
    src/shape/shape.cpp
    src/shape/sphere.cpp
    src/shape/triangle_list.cpp
    src/shape/box.cpp
)

set(SOURCES 
    src/camera.cpp
    src/light.cpp
    src/ray.cpp
    src/scene.cpp
    src/film.cpp
    src/raycaster.cpp
    src/transform.cpp
    ${SHAPE_SOURCES}
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} stb_image homo_math)
