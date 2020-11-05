#pragma once
#include "Matrix.h"
#include "Vector.h"

namespace HomoRT{
    //the rotation vector in transfrom is euler angle
    class Transform{
    public:
        Transform();
        Transform(Math::Vector3 position,Math::Vector3 rotation,Math::Vector3 scale);

        Transform(Math::Mat4x4 trans);
        inline Math::Mat4x4 GetTrans(){return transform;}
        Math::Vector4 GetTrans(Math::Vector4 vec);
        inline Math::Mat4x4 GetInvTrans() {return inv_transform;}
        Math::Vector4 GetInvTrans(Math::Vector4 vec);

        void SetPosition(Math::Vector3 position){this->position = position;UpdateTransform();}
        Math::Vector3 GetPosition(){return position;}

        void SetRotation(Math::Vector3 rotation){this->rotation = rotation;UpdateTransform();}
        Math::Vector3 GetRotation(Math::Vector3 rotation){return rotation;}

        void SetScale(Math::Vector3 scale){this->scale = scale;UpdateTransform();}
        Math::Vector3 GetScale(){return scale;}

    private:
        void UpdateTransform();

        Math::Vector3 position,rotation,scale;
        Math::Mat4x4 transform;
        Math::Mat4x4 inv_transform;
    };
}