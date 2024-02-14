#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std::chrono;

#include "scr/rtweekend.h"          // Inclui funções utilitárias relacionadas ao tempo
#include "scr/hittable.h"           // Inclui a definição de objetos que podem ser atingidos por raios
#include "scr/hittable_list.h"      // Inclui a lista de objetos atingíveis
#include "scr/sphere.h"             // Inclui a definição de esferas
#include "scr/triangle.h"           // Inclui a definição de triângulos
#include "scr/object.h"             // Inclui a definição de objetos complexos
#include "scr/export_image.cpp"     // Inclui funções para exportar imagens
#include "scr/color.h"              // Inclui definições de cores
#include "scr/camera.h"             // Inclui a definição da câmera
#include "scr/animation.h"          // Inclui a definição de animação

int main() {

    auto start = high_resolution_clock::now();   // Registra o tempo de início da execução do programa

    hittable_list world;        // Lista de objetos na cena

    // Definição dos materiais para os objetos na cena
    auto black = make_shared<lambertian>(color(0, 0, 0));                  // Chão preto
    auto platinum = make_shared<metal>(color(0.8, 0.8, 0.8), 0.05);        // Cubo de platina
    auto matte_blue = make_shared<lambertian>(color(0.1, 0.3, 0.8));       // Segundo cubo azul fosco
    auto glass = make_shared<dielectric>(1.5);                            // Esfera de vidro

    // Criação dos objetos na cena
    shared_ptr<object> cubo1 = make_shared<object>("objetos/cube.obj", platinum, 1, vec3(0, -2, -2), vec3(90, 0, 0)); // Cubo de platina
    shared_ptr<object> cubo2 = make_shared<object>("objetos/cube.obj", matte_blue, 2, vec3(6, 1, 0), vec3(15, 45, 0)); // Segundo cubo azul fosco
    shared_ptr<sphere> chao = make_shared<sphere>(point3( 0.0, -101, -1.0), 100.0, black); // Chão preto
    shared_ptr<sphere> circulo = make_shared<sphere>(point3( 2.7,    1, -2.5),   1, glass); // Esfera de vidro

    // Adiciona os objetos na cena à lista de objetos
    world.add(chao);        // Chão preto
    world.add(circulo);     // Esfera de vidro
    world.add(cubo1);       // Cubo de platina
    world.add(cubo2);       // Segundo cubo azul fosco

    camera camera;   // Criação da câmera

    // Configurações da câmera
    camera.aspect_ratio      = 16.0 / 9.0;
    camera.image_width       = 800;
    camera.samples_per_pixel = 200;
    camera.max_depth         = 100;
    camera.vfov              = 60;
    camera.lookat            = point3(3,2,0);
    camera.vup               = vec3(0,1,0);

    // Configurações da animação
    int duration = 5;
    int frames_per_second = 15;
    int total_frames = duration * frames_per_second;
    animation camera_anim = animation(
        point3(0, 4, 0),
        7.0,
        360.0/total_frames
    );

    // Loop para renderizar cada frame da animação
    for (int i = 0; i < total_frames; i++) {

        auto frame_start = high_resolution_clock::now();    // Registra o tempo de início da renderização do frame
        
        camera.lookfrom = camera_anim.get_position(i);      // Atualiza a posição da câmera para este frame

        cubo1->rotate_mat3(vec3(0, 0, 100), 100);

        camera.render(world, "frame_" + std::to_string(i)); // Renderiza o frame atual

        auto frame_Stop = high_resolution_clock::now();     // Registra o tempo de término da renderização do frame
        auto frame_duration = duration_cast<std::chrono::seconds>(frame_Stop - frame_start);
        std::cout << "Tempo estimado de renderizacao: " << (total_frames - i - 1) * frame_duration.count() << " segundos." << std::endl;
    }

    return 0; 
}
