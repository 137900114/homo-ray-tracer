#pragma once
#include "shape.h"
#include "ray.h"

namespace HomoRT{
    class Sphere : public Shape{
    public:
        Sphere(float radius,Transform trans):Shape(trans){
            this->radius = radius;
        }

        virtual BBox GetBoundBox() override;
        virtual bool Intersect(Ray& ray,Intersection& inter) override;
    private:
        float radius;
    };

}