#pragma once
#include <stdint.h>
#include "Vector.h"

namespace HomoRT {
    enum FILM_WRITE_FILE_TYPE{
        BMP
    };

    struct FilmBlendParameter{
        float new_blend;
        float old_blend;
        FilmBlendParameter(float new_blend,float old_blend){
            this->new_blend = new_blend > 0 ? new_blend : 0;
            this->old_blend = old_blend > 0 ? old_blend : 0;
        }
    };

    class Film{
    public:
        Film(uint32_t width,uint32_t height)
            :width(width),height(height){
            data = new char[width * height * 3];
        }
        virtual ~Film() {delete data;}
        void Save(const char* filename,FILM_WRITE_FILE_TYPE type = BMP);

        void Set(uint32_t x,uint32_t y,Math::Vector3 color,FilmBlendParameter blend = FilmBlendParameter(1.,0.));
        Math::Vector3 Get(uint32_t x,uint32_t y);

        uint32_t GetWidth(){return width;}
        uint32_t GetHeight(){return height;}
    private:
        char* data;
        uint32_t width,height;
    };
}