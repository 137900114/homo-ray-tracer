#include "film.h"
#include "stb_image.h"
using namespace HomoRT;

void Film::set(uint32_t x,uint32_t y,Math::Vector3 color){
    char r = static_cast<uint8_t>(color.x * 256.),
    g = static_cast<uint8_t>(color.y * 256.),
    b = static_cast<uint8_t>(color.z * 256.);

    if(x < width && y < height){
        data[x + y * width ] = r;
        data[x + y * width + 1] = g;
        data[x + y * width + 2] = b;
    }
}

void Film::save(const char* filename,FILM_WRITE_FILE_TYPE type){
    switch(type){
    case FILM_WRITE_FILE_TYPE::BMP:
        stbi_write_bmp(filename,width,height,3,data);
    }
}