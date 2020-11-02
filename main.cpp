#include <iostream>
#include "stb_image.h"
#include "Vector.h"
#include "shape/shape.h"

int main(){
    char image[256][256][3];

    for(int i = 0;i != 256;i++){
        for(int j = 0;j != 256;j++){
            image[i][j][0] = i;
            image[i][j][1] = j;
            image[i][j][2] = 255;
        }
    }

    stbi_flip_vertically_on_write(true);
    stbi_write_bmp("../output/test_stb.bmp",256,256,3,image);
 

    Math::Vector3 v1 = Math::Vector3(1,1,4),v2 = Math::Vector3(5,1,4);
    std::cout << Math::dot(v1,v2);
}