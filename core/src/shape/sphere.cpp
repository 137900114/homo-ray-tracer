#include "sphere.h"
#include "Vector.h"

using namespace HomoRT;

BBox Sphere::GetBoundBox(){
    BBox result(this->transform.GetPosition(),this->transform.GetPosition());
    result.max = result.max + radius;
    result.min = result.min - radius;
}