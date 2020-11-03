#pragma once
#include "Matrix.h"
#include "Vector.h"

//the rotation vector in transfrom is euler angle
class Transform{
public:
    Transform() : position(),rotation(),scale(1,1,1){
        transform = Math::Mat4x4::I(),inv_transform = Math::Mat4x4::I();
    }
    Transform(Math::Vector3 position,Math::Vector3 rotation,Math::Vector3 scale)
        : position(position),rotation(rotation),scale(scale){
            transform = Math::PackTransfrom(position,rotation,scale);
    }

    Transform(Math::Mat4x4 trans)
        :transform(trans){
            Math::UnpackTransfrom(trans,position,rotation,scale);
            inv_transform = trans.R();
    }

    inline Math::Mat4x4 GetTrans(){return transform;}
    inline Math::Vector4 GetTrans(const Math::Vector4& vec) {return Math::mul(transform,vec);}
    inline Math::Mat4x4 GetInvTrans() {return inv_transform;}
    inline Math::Vector4 GetInvTrans(const Math::Vector4& vec) {return Math::mul(inv_transform,vec);}

    void SetPosition(Math::Vector3 position){this->position = position;UpdateTransform();}
    Math::Vector3 GetPosition(){return position;}

    void SetRotation(Math::Vector3 rotation){this->rotation = rotation;UpdateTransform();}
    Math::Vector3 GetRotation(Math::Vector3 rotation){return rotation;}

    void SetScale(Math::Vector3 scale){this->scale = scale;UpdateTransform();}
    Math::Vector3 GetScale(){return scale;}

private:
    inline void UpdateTransform(){
        transform = Math::PackTransfrom(position,rotation,scale);
        inv_transform = transform.R();
    }

    Math::Vector3 position,rotation,scale;
    Math::Mat4x4 transform;
    Math::Mat4x4 inv_transform;
};