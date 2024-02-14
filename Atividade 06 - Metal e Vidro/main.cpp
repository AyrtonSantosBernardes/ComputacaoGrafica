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

    auto black = make_shared<lambertian>(color(0, 0, 0));                  // Chão preto
    auto platinum = make_shared<metal>(color(0.8, 0.8, 0.8), 0.05);        // Cubo de platina
    auto matte_blue = make_shared<lambertian>(color(0.1, 0.3, 0.8));       // Segundo cubo azul fosco
    auto glass = make_shared<dielectric>(1.5);                            // Esfera de vidro

    world.add(make_shared<sphere>(point3( 0.0, -101, -1.0), 100.0, black)); // Chão preto
    world.add(make_shared<sphere>(point3( 2.7,    1, -2.5),   1, glass));      // Esfera de vidro
    world.add(make_shared<object>("objetos/cube.obj", platinum, 1, vec3(0, -2, -2), vec3(90, 0, 0))); // Cubo de platina
    world.add(make_shared<object>("objetos/cube.obj", matte_blue, 3, vec3(6, 1, 0), vec3(15, 45, 0))); // Segundo cubo azul fosco

    camera camera;

    camera.aspect_ratio      = 16.0 / 9.0;
    camera.image_width       = 800;
    camera.samples_per_pixel = 200;
    camera.max_depth         = 100;

    camera.vfov     = 60;
    camera.lookfrom = point3(3,2,5);
    camera.lookat   = point3(3,2,0);
    camera.vup      = vec3(0,1,0);

    camera.render(world, "camera");
}
