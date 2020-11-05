#include "shape/box.h"
#include "Matrix.h"
#include <iostream>
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

inline Math::Vector3 hit_plane(int dim,float plane,Math::Vector3& pos,Math::Vector3& dir,float& t){
    printf("%f\n",dir[dim]);
    t = (plane - dir[dim]) / dir[dim];
    return pos +  dir * ((plane - dir[dim]) / dir[dim]);
}



bool Box::Intersect(Ray& r,Intersection& inter){
    Math::Vector4 r_pos = Math::Vector4(r.o,1.),r_dir = Math::Vector4(r.d,0.);

    Math::Vector3  r_pos_object = Math::Vector3(GetWorldToObject(r_pos)),
        r_dir_object = Math::Vector3(GetWorldToObject(r_dir));
   
    int dim;
    float t = std::numeric_limits<float>::max();
    bool is_intersected = false;
    for(int i = 0;i != 3;i++){
        int dim_sub_1 = (i + 1) % 3,dim_sub_2 = (i + 2) % 3;

        float ray_t;
        printf("b");
        Math::Vector3 P1 = hit_plane(i,- 1.,r_pos_object,r_dir_object,ray_t);
        if(is_inside(P1[dim_sub_1],P1[dim_sub_2],1. ,1.,
            -1.,-1.) && ray_t < r.maxt && r.mint < ray_t){
                is_intersected = true;
                if(ray_t < t){ t = ray_t; dim = i; }
        }
        Math::Vector3 P2 = hit_plane(i,1.,r_pos_object,r_dir_object,t);
        if(is_inside(P2[dim_sub_1],P2[dim_sub_2],1.,1.,-1.,-1.)
                && t < r.maxt && r.mint < t ){
                is_intersected = true;
                if(ray_t < t) { t = ray_t; dim = i;}
        }
    }

    if(!is_intersected) return false;
    Math::Vector4 object_normal = Math::Vector4();
    object_normal[dim] = 1.;

    inter.r = &r;
    inter.normal = Math::Vector3(Math::normalize(GetObjectToWorld(object_normal)));
    inter.t = t;
    return true;
}


BSphere Box::GetBoundSphere(){
    Math::Vector3 scale = transform.GetScale();
    float radius = length(scale);

    return BSphere(transform.GetPosition(),radius);
}

template<bool is_max>
inline Math::Vector3 merge_by_max_or_min(Math::Vector3& vec1,Math::Vector3& vec2){
    if constexpr(is_max){
        return Math::Vector3(Math::fmax(vec1.x,vec2.x),Math::fmax(vec1.y,vec2.y),Math::fmax(vec1.z,vec2.z));
    }else{
        return Math::Vector3(Math::fmin(vec1.x,vec2.x),Math::fmin(vec1.y,vec2.y),Math::fmin(vec1.z,vec2.z)); 
    }
}

inline Math::Vector3 get_vertex(int index){
    Math::Vector3 v;
    v.x = index & 1 ? 1 : -1;
    v.y = index & 2 ? 1 : -1;
    v.z = index & 4 ? 1 : -1;
    return v;
}

BBox Box::GetBoundBox(){
    constexpr float float_max = std::numeric_limits<float>::max();
    constexpr float float_min = std::numeric_limits<float>::min();
    Math::Vector3 bmax = Math::Vector3(float_max,float_max,float_max);
    Math::Vector3 bmin = Math::Vector3(float_min,float_min,float_min);

    for(int i = 0;i < 8;i++){
        Math::Vector3 pos = Math::Vector3(GetObjectToWorld(Math::Vector4(get_vertex(i),1.)));

        bmax = merge_by_max_or_min<true>(pos,bmax);
        bmin = merge_by_max_or_min<false>(pos,bmin);
    }

    return BBox(bmax,bmin);
    
}


