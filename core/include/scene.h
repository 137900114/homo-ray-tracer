#pragma once
#include "shape/shape.h"
#include "ray.h"
#include <Vector>


namespace HomoRT{
    class Scene{
    public:
        virtual bool Intersect(Ray& r,Intersection& inter) = 0;
    };

    class SequenceScene : public Scene{
    public:
        void InsertShape(Shape* shape){
            shapes.push_back(shape);
        }
        virtual bool Intersect(Ray& r,Intersection& iter);
    private:
        std::vector<Shape*> shapes;
    };
}