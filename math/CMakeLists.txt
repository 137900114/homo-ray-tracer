project(homo_math)

set(SOURCES 
    src/Matrix.cpp
    src/Vector.cpp
)

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)