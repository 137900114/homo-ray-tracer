#include "film.h"
#include "stb_image.h"
#include "MathFunctions.h"
using namespace HomoRT;

inline char float_to_char_comp(float f){
    //if the f equals 1 the value of this function may be 256 if we don't do this step
    f = clamp(.9999,0.,f);
    return static_cast<char>(f * 256.);
}

inline float char_comp_to_float(char c){
    return static_cast<float>(c) / 256.;
}

#include <stdio.h>

void Film::Set(uint32_t x,uint32_t y,Math::Vector3 color,FilmBlendParameter blend){
    
    if(blend.old_blend != 0. && blend.new_blend != 1.){
        Math::Vector3 old_color = Get(x,y);
        color = old_color * blend.old_blend + color * blend.new_blend;
    }
    
    char r = float_to_char_comp(color.x),
    g = float_to_char_comp(color.y),
    b = float_to_char_comp(color.z);


    if(x < width && y < height){ 
        data[x * 3 + y * width * 3] = r;
        data[x * 3 + y * width * 3 + 1] = g;
        data[x * 3 + y * width * 3 + 2] = b;
        //printf("%c %c %c\n",data[x + y * width * 3 + 0],data[x + y * width * 3 + 1],data[x + y * width * 3 + 2]);
    }
}

bool Film::Save(const char* filename,bool flip_vertically,FILM_WRITE_FILE_TYPE type){
    stbi_flip_vertically_on_write(flip_vertically);
    
    switch(type){
    case FILM_WRITE_FILE_TYPE::BMP:
        return stbi_write_bmp(filename,width,height,3,data) == 0;
    }
    return false;
}

//if the x,y coordinate is out of the film's pixel range we will get a (0,0,0) color
Math::Vector3 Film::Get(uint32_t x,uint32_t y){
    Math::Vector3 color = Math::Vector3();
    
    if(x < width && y < height){
        color.x = char_comp_to_float(data[x * 3 + y * 3 * width]);
        color.y = char_comp_to_float(data[x * 3 + y * 3 * width + 1]);
        color.z = char_comp_to_float(data[x * 3 + y * 3 * width + 2]);
    }
    return color;
}