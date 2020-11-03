#pragma once
#include "shape/shape.h"
#include "ray.h"
#include <Vector>


namespace HomoRT{
    class Scene{
    public:
        virtual void Intersect(Ray& r,Intersection& inter) = 0;
    };

    class SequenceScene : public Scene{
    public:
        void InsertShape(Shape* shape){
            shapes.push_back(shape);
        }
        virtual void Intersect(Ray& r,Intersection& iter) = 0;
    private:
        std::vector<Shape*> shapes;
    };
}