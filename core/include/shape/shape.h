#pragma once

#include "transform.h"
#include "ray.h"
#include "bbox.h"


namespace HomoRT{
    class Shape{
    public:
        virtual bool Intersect(Ray& r,Intersection& inter) = 0;

        inline Math::Mat4x4 GetObjectToWorld() {return transform.GetTrans();}
        inline Math::Mat4x4 GetWorldToObject() {return transform.GetInvTrans();}
        inline Math::Vector4 GetObjectToWorld(const Math::Vector4& vec) {return transform.GetTrans(vec);}
        inline Math::Vector4 GetWorldToObject(const Math::Vector4& vec) {return transform.GetInvTrans(vec);}

        Shape(Transform trans):transform(trans){}
        virtual BBox GetBoundBox()  = 0;
        virtual BSphere GetBoundSphere() = 0;
    protected:
        Transform transform;
    }; 
}