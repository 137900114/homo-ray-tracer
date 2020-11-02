
#include <stdint.h>
#include "Vector.h"

namespace HomoRT {
    enum FILM_WRITE_FILE_TYPE{
        BMP
    };

    class Film{
    public:
        Film(uint32_t width,uint32_t height)
            :width(width),height(height){
            data = new char[width * height * 3];
        }
        virtual ~Film() {delete data;}
        void save(const char* filename,FILM_WRITE_FILE_TYPE type = BMP);

        void set(uint32_t x,uint32_t y,Math::Vector3 color);
    private:
        char* data;
        uint32_t width,height;
    };
}