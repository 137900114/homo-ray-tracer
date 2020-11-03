#include "shape/sphere.h"
#include "Vector.h"

using namespace HomoRT;

BBox Sphere::GetBoundBox(){
    BBox result(this->transform.GetPosition(),this->transform.GetPosition());
    result.max = result.max + radius;
    result.min = result.min - radius;

    return result;
}

BSphere Sphere::GetBoundSphere(){
    return BSphere(transform.GetPosition(),radius);
}

bool Sphere::Intersect(Ray& r,Intersection& inter){
    Math::Vector3 pos = transform.GetPosition();

    Math::Vector3 o = r.o - pos;
    float c = Math::dot(o,o) - radius * radius;
    float b = 2 * Math::dot(o,r.d);
    float a = Math::dot(r.d,r.d);

    float delta = b * b - 4 * a *c;
    if(delta < 0) return false;

    delta = sqrtf(delta);
    
    Math::Vector3 hit_point;
    
    float t0 = (- b + delta) / 2 * a ,t1 = (-b - delta) / 2 * a;

    if(t1 > r.maxt) return false;
    if(t1 > r.mint) inter.t = t1;
    else if(t0 > r.mint) inter.t = t0;
    else return false;
    
    inter.r = &r;
    inter.normal = Math::normalize((r.o + r.d * inter.t) - pos);
    
    return true;
}

