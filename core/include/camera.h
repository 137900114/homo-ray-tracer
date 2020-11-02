#include "ray.h"
#include "sampler.h"
#include "transform.h"
#include <stdint.h>

namespace HomoRT{
    class Camera{
    public:
        //camera class will generate the corresponding ray
        //according to some attributes.
        //@param filmwidth the width of the camera's film
        //@param filmheight the height of the camera's film
        //@param trans a transform object describes the position of the camera in the space
        //@param len_radius the radius of the camera's len.This parameter is needed while calculating depth of field,
        //otherwise just ignore it.
        Camera(uint32_t filmwidth,uint32_t filmheight,
                const Transform& trans,float len_radius = 0.);

        //this two functions is not required to implemented by the child classes.
        virtual bool GenerateRay(CameraSample& sample,Ray& r) {return false;}
        virtual bool GenerateRay(uint32_t x,uint32_t y,Ray& r) {return false;}

        Transform& GetTransform() {return transform;}
    protected:
        Transform transform;
        float filmwidth,filmheight;
        float len_radius;
    };


    class PerspectiveCamera : public Camera{
    public:
        PerspectiveCamera(uint32_t filmwidth,uint32_t filmheight,const Transform& trans,
            float fov,float near,float far);
        virtual bool GenerateRay(uint32_t x,uint32_t t,Ray& r) override;
    private:
        float fov,near,far,aspect;
    };
}


