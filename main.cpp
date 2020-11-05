#include <iostream>
#include "film.h"
#include "Vector.h"
#include "shape/shape.h"
#include "camera.h"
#include "scene.h"
#include "shape/box.h"
#include "raycaster.h"

using namespace HomoRT;

int main(){
    /*Film film(1024,1024);
    Math::Mat4x4 mat = Math::Mat4x4::I();

    printf("camera");
    PerspectiveCamera camera(1024,1024,Transform(Math::Vector3(),Math::Vector3(),Math::Vector3(1.,1.,1.)),
        PI / 4.,1e-1,1e4);
    SequenceScene scene;

    printf("box");
    Box box(Math::Vector3(0.,0.,5.));

    scene.InsertShape(&box);
    
    RayCaster rc(&film,&camera,&scene);

    printf("cast");
    rc.CastRay();

    if(!film.Save("../output/test_film.bmp",true)){
        printf("the film saved the film data successfully\n");
    }else {
        printf("fail to save the film data\n");
    }*/
    Transform trans(Math::Vector3(4.,5.,6.),Math::Vector3(0.,0.,0.),Math::Vector3(1.,2.,3.));
    
    Math::Mat4x4 mat = Math::Mat4x4::I();

    Math::mul(mat,Math::Vector4(1.,1.,1.,1.)) ;
}