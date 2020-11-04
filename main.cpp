#include <iostream>
#include "film.h"
#include "Vector.h"
#include "shape/shape.h"
#include "camera.h"
#include "scene.h"
#include "shape/sphere.h"
#include "raycaster.h"

using namespace HomoRT;

int main(){
    Film film(256,256);
    PerspectiveCamera camera(256,256,Transform(Math::Vector3(),Math::Vector3(),Math::Vector3(1.,1.,1.)),
        PI / 4.,1e-1,1e4);
    SequenceScene scene;

    Sphere sphere(3.,Transform(Math::Vector3(0.,0.,100.),Math::Vector3(),Math::Vector3(1.,1.,1.)));
    scene.InsertShape(&sphere);
    
    RayCaster rc(&film,&camera,&scene);

    rc.CastRay();

    if(!film.Save("../output/test_film.bmp",true)){
        printf("the film saved the film data successfully\n");
    }else {
        printf("fail to save the film data\n");
    }
}