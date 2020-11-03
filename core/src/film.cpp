#include "film.h"
#include "stb_image.h"
#include "MathFunctions.h"
using namespace HomoRT;

inline uint8_t float_to_char_comp(float f){
    //if the f equals 1 the value of this function may be 256 if we don't do this step
    f = clamp(.9999,0.,f);
    return static_cast<uint8_t>(f * 256.);
}

inline float char_comp_to_float(char c){
    return static_cast<uint8_t>(c) / 256.;
}


void Film::Set(uint32_t x,uint32_t y,Math::Vector3 color,FilmBlendParameter blend){
    
    if(blend.old_blend != 0. && blend.new_blend != 1.){
        Math::Vector3 old_color = Get(x,y);
        color = old_color * blend.old_blend + color * blend.new_blend;
    }
    
    uint8_t r = float_to_char_comp(color.x),
    g = float_to_char_comp(color.y),
    b = float_to_char_comp(color.z);

    if(x < width && y < height){
        data[x + y * width * 3] = r;
        data[x + y * width * 3 + 1] = g;
        data[x + y * width * 3 + 2] = b;
    }
}

void Film::Save(const char* filename,FILM_WRITE_FILE_TYPE type){
    switch(type){
    case FILM_WRITE_FILE_TYPE::BMP:
        stbi_write_bmp(filename,width,height,3,data);
    }
}

//if the x,y coordinate is out of the film's pixel range we will get a (0,0,0) color
Math::Vector3 Film::Get(uint32_t x,uint32_t y){
    Math::Vector3 color = Math::Vector3();
    
    if(x < width && y < height){
        color.x = char_comp_to_float(data[x + y * 3 * width]);
        color.y = char_comp_to_float(data[x + y * 3 * width + 1]);
        color.z = char_comp_to_float(data[x + y * 3 * width + 2]);
    }
    return color;
}