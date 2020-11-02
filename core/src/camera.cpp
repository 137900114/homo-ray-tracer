#include "camera.h"
#include "MathFunctions.h"

using namespace HomoRT;


Camera::Camera(uint32_t filmwidth,uint32_t filmheight,
    const Transform& trans,float len_radius) : transform(trans){
    this->filmwidth =  static_cast<float>(filmwidth);
    this->filmheight = static_cast<float>(filmheight);
    //the len radius has to be greater than 0.
    this->len_radius = Math::fmax(len_radius,0.);
}

PerspectiveCamera::PerspectiveCamera(uint32_t filmwidth,uint32_t filmheight,const Transform& trans,
    float fov,float near,float far):Camera(filmwidth,filmheight,trans),
        near(near),far(far){
    this->aspect = this->filmwidth / this->filmheight;
    this->fov = tanf(fov / 2.);
}

bool PerspectiveCamera::GenerateRay(uint32_t _x,uint32_t _y,Ray& r){
    float x = static_cast<float>(_x),y = static_cast<float>(_y);

    if(x > filmwidth || y > filmheight)
        return false;

    Math::Vector3 position = transform.GetPosition();
    r.o = position;

    r.mint = near,r.maxt = far;
    Math::Vector3 camera_space_dir = Math::Vector3( (x / filmwidth * 2. - 1.) * fov * aspect,
        (y / filmheight * 2. - 1.) * fov, 1.);

    r.d = Math::Vector3(Math::mul(transform.GetTrans(),Math::Vector4(camera_space_dir,0.))); 
    r.d = Math::normalize(r.d);

    return true;
}