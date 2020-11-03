#pragma once

#include "camera.h"
#include "film.h"
#include "sampler.h"
#include "scene.h"


namespace HomoRT{
    class RayCaster{
    public:
        RayCaster(Film* film,Camera* camera,Scene* scene,Sampler* sampler = nullptr){
            this->film = film;
            this->scene = scene;
            this->sampler = sampler;

            if(sampler == nullptr){
                sample_x = 1,sample_y = 1;
            }
            filmwidth = film->GetWidth();
            filmheight = film->GetHeight();
        }
        
        //trying to cast rays to intersect with the scene
        //the number of ray cast to the scene will be determined by width and height of the filmRay& r,Intersection& iter
        void CastRay();
    private:
        Film* film;
        Sampler* sampler;

        Camera* camera;
        Scene* scene;

        uint32_t filmwidth,filmheight;
        uint32_t sample_x,sample_y;
    };
}