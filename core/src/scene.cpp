#include "scene.h"
#include <limits>

using namespace HomoRT;

void SequenceScene::Intersect(Ray& r,Intersection& inter){
    Intersection temp_inter;
    inter.t = std::numeric_limits<float>::max();
    for(auto& item : shapes){
        if(item->Intersect(r,temp_inter)){
            if(temp_inter.t < inter.t) inter = temp_inter;
        }
    }
}