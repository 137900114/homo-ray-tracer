#pragma once
#include "Vector.h"
#include "MathFunctions.h"
#include <limits>
#include "ray.h"

namespace HomoRT{
    struct BBox{
        Math::Vector3 max;
        Math::Vector3 min;


        BBox(){
            float float_max = std::numeric_limits<float>::max();
            float float_min = std::numeric_limits<float>::min();

            max = Math::Vector3(float_max,float_max,float_max);
            min = Math::Vector3(float_min,float_min,float_min);
        }

        BBox(Math::Vector3 max,Math::Vector3 min){
            //every dimension of the upper bound of the bound box should not be smaller than the corresponding deminsion in the lower bound
            this->max = Math::Vector3(Math::fmax(max[0],min[0]),Math::fmax(max[1],min[1]),Math::fmax(max[2],min[2]));
            this->min = min;
        }

        bool Intersect(Ray& r);
        BBox Merge(BBox& other);
    };

    struct BSphere{
        Math::Vector3 pos;
        float radius;

        BSphere(){
            radius = std::numeric_limits<float>::max();
            pos = Math::Vector3();
        }

        BSphere(Math::Vector3 pos,float radius){
            this->pos = pos;
            this->radius = radius;
        }

        BSphere Merge(BSphere& other);
        bool Intersect(Ray& r);        
    };
}