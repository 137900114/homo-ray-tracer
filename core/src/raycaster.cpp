#include "raycaster.h"
#include <limits>
#include <stdio.h>

using namespace HomoRT;

void RayCaster::CastRay(){

    for(uint32_t x = 0;x != this->filmwidth;x++){
        for(uint32_t y = 0;y != this->filmheight;y++){
            Math::Vector3 color = Math::Vector3();
            Ray r;
            Intersection inter;
            if(camera->GenerateRay(x,y,r)){
                if(scene->Intersect(r,inter)){
                    //currently we assume there is a default light whose direction is (-1,-1,0.)
                    color = dot(inter.normal,Math::normalize(Math::Vector3(0.,0.,-1.)));
                }
            }
            film->Set(x,y,color);
            
        }
    }
}