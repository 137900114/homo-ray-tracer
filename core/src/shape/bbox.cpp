#include "shape/bbox.h"
using namespace HomoRT;


inline bool is_inside(float x,float y,float upper_x,float upper_y,float lower_x,float lower_y){
    if(x > upper_x || x < lower_x){
        return false;
    }
    if(y > upper_y || y < lower_y){
        return false;
    }
    return true;
}

inline Math::Vector3 hit_plane(int dim,float plane,Ray& r){
    return r.o +  r.d * ((plane - r.o[dim]) / r.d[dim]);
}


bool BBox::Intersect(Ray& r){
    Math::Vector3 P1,P2;
    
    for(int i = 0;i != 3;i++){
        int dim_sub_1 = (i + 1) % 3,dim_sub_2 = (i + 2) % 3;
        float upper_x = max[dim_sub_1],upper_y = max[dim_sub_2],
            lower_x = min[dim_sub_1],lower_y = min[dim_sub_2];

        P1 = hit_plane(i,min[i],r);
        if(is_inside(P1[dim_sub_1],P1[dim_sub_2],upper_x,upper_y,
            lower_x,lower_y)){
                return true;
        }
        P2 = hit_plane(i,max[i],r);
        if(is_inside(P2[dim_sub_1],P2[dim_sub_2],upper_x,upper_y,
            lower_x,lower_y)){
                return true;
        }
    }
    return false;
}

BBox BBox::Merge(BBox& other){
    Math::Vector3 max_vec = Math::Vector3(Math::fmax(max[0] , other.max[0]),Math::fmax(max[1],other.max[1]),Math::fmax(max[2],other.max[2]));
    Math::Vector3 min_vec = Math::Vector3(Math::fmin(min[0] , other.min[0]),Math::fmin(min[1],other.min[1]),Math::fmin(min[2],other.min[2]));

    return BBox(max_vec,min_vec);
}

bool BSphere::Intersect(Ray& r){

    Math::Vector3 o = r.o - pos;
    float c = Math::dot(o,o) - radius * radius;
    float b = 2 * Math::dot(o,r.d);
    float a = Math::dot(r.d,r.d);

    float delta = b * b - 4 * a *c;
    if(delta < 0) return false;

    delta = sqrtf(delta);
    
    float t0 = (- b + delta) / 2 * a ,t1 = (-b - delta) / 2 * a;
    if(t0 < r.mint || t1 > r.maxt) return false;


}

BSphere BSphere::Merge(BSphere& other){
    float distance = Math::length(other.pos - pos);
    if(other.radius + distance < radius){
        return *this;
    }else if(other.radius > distance + radius){
        return other;
    }

    float new_radius = (other.radius + this->radius + distance) * .5;
    Math::Vector3 new_position = pos + (other.pos - pos)* (new_radius - radius) / distance;

    return BSphere(new_position,new_radius); 
}