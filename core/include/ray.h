#pragma once
#include "Vector.h"

namespace HomoRT{
    struct Ray{
        Math::Vector3 o,d;
        float mint,maxt;
    };

    struct Intersection {
        Ray* r;
        float t;
        Math::Vector3 normal;
    };
}