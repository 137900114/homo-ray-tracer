#pragma once
#include "shape/shape.h"
#include "transform.h"
#include "ray.h"

namespace HomoRT{
    class Box : public Shape {
    public:
        Box(Math::Vector3 position,Math::Vector3 rotation = Math::Vector3(),Math::Vector3 scale = Math::Vector3(1.,1.,1.)):
            Shape(Transform(position,rotation,scale)){}
        virtual bool Intersect(Ray& r,Intersection& inter) override;
        virtual BBox GetBoundBox() override;
        virtual BSphere GetBoundSphere() override;
    };
}