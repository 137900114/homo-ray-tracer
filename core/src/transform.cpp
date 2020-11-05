#include "transform.h"
using namespace HomoRT;


Transform::Transform() : position(),rotation(),scale(1,1,1){
        transform = Math::Mat4x4::I(),inv_transform = Math::Mat4x4::I();
}
Transform::Transform(Math::Vector3 position,Math::Vector3 rotation,Math::Vector3 scale)
    : position(position),rotation(rotation),scale(scale){
        transform = Math::PackTransfrom(position,rotation,scale);
        inv_transform = transform.R();
}

Transform::Transform(Math::Mat4x4 trans)
    :transform(trans){
        Math::UnpackTransfrom(trans,position,rotation,scale);
        inv_transform = trans.R();
}

Math::Vector4 Transform::GetTrans(Math::Vector4 vec) {return Math::mul(transform,vec);}
Math::Vector4 Transform::GetInvTrans(Math::Vector4 vec) {
    return Math::mul(inv_transform,vec);
}


void Transform::UpdateTransform(){
    transform = Math::PackTransfrom(position,rotation,scale);
    inv_transform = transform.R();
}