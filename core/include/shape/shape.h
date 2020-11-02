#include "transform.h"
#include "ray.h"
#include "bbox.h"


namespace HomoRT{
    class Shape{
    public:
        virtual bool Intersect(Ray& r,Intersect& inter);

        inline Math::Mat4x4 GetObjectToWorld() {return transform.GetTrans();}
        inline Math::Mat4x4 GetWorldToObject() {return transform.GetInvTrans();}
        inline Math::Vector4 GetObjectToWorld(const Math::Vector4& vec) {return transform.GetTrans(vec);}
        inline Math::Vector4 GetWorldToObject(const Math::Vector4& vec) {return transform.GetInvTrans(vec);}

        Shape(Transform trans):transform(trans){}
        inline BBox GetBoundBox() {return bound_box;}
    protected:
        Transform transform;
        BBox bound_box;
    }; 
}