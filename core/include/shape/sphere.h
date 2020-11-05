#pragma once
#include "shape.h"
#include "ray.h"

namespace HomoRT{
    class Sphere : public Shape{
    public:
        Sphere(float radius,Math::Vector3 position,Math::Vector3 rotation = Math::Vector3(0.,0.,0.)):
            Shape(Transform(position,rotation,Math::Vector3(radius,radius,radius))){
            this->radius = radius;
        }

        virtual BBox GetBoundBox() override;
        virtual BSphere GetBoundSphere() override;
        virtual bool Intersect(Ray& ray,Intersection& inter) override;
    private:
        float radius;
    };

}