#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "scr/rtweekend.h"

#include "scr/hittable.h"
#include "scr/hittable_list.h"
#include "scr/sphere.h"
#include "scr/triangle.h"
#include "scr/object.h"

#include "scr/export_image.cpp"
#include "scr/color.h"
#include "scr/camera.h"

int main() {
    hittable_list world;

    world.add(make_shared<sphere>(point3( 0.0, -101, -1.0), 100.0)); 
    world.add(make_shared<sphere>(point3( 2.7,    1, -2.5),   1));     
    world.add(make_shared<object>("objetos/cube.obj", 1, vec3(0, -2, -2), vec3(90, 0, 0)));
    world.add(make_shared<object>("objetos/cube.obj", 3, vec3(6, 1, 0), vec3(15, 45, 0)));

    camera cam, cam2;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    cam.vfov     = 90;
    cam.lookfrom = point3(4,2,4);
    cam.lookat   = point3(3,2,0);
    cam.vup      = vec3(0,1,0);

    cam.render(world, "camera1");

    cam2.aspect_ratio      = 16.0 / 9.0;
    cam2.image_width       = 400;
    cam2.samples_per_pixel = 100;
    cam2.max_depth         = 50;

    cam2.vfov     = 60;
    cam2.lookfrom = point3(0,5,7);
    cam2.lookat   = point3(3,2,0);
    cam2.vup      = vec3(0,2,0);

    cam2.render(world, "camera2");
}
