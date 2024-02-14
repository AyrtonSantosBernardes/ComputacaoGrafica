#include <fstream>
#include <iostream>
#include <vector>

#include "src/Image.cpp"
#include "src/vec3.h"
#include "src/object_reader.h"
#include "src/color.h"
#include "src/ray.h"

bool hit_sphere(const vec3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant >= 0);
}

bool hit_triangle(const vec3& vertex0, const vec3& vertex1, const vec3& vertex2, const ray& r) {
    vec3 e1 = vertex1 - vertex0;
    vec3 e2 = vertex2 - vertex0;
    vec3 h = cross(r.direction(), e2);
    double a = dot(e1, h);

    if (a > -1e-6 && a < 1e-6)
        return false;

    double f = 1.0 / a;
    vec3 s = r.origin() - vertex0;
    double u = f * dot(s, h);

    if (u < 0.0 || u > 1.0)
        return false;

    vec3 q = cross(s, e1);
    double v = f * dot(r.direction(), q);

    if (v < 0.0 || u + v > 1.0)
        return false;

    double t = f * dot(e2, q);

    return (t > 0.0001);
}

color ray_color(const ray& r, std::string geometricForm = "sphere", std::vector<vec3>* obj_vertices = nullptr, std::vector<mat3>* obj_faces = nullptr) {
    if (geometricForm == "sphere") {
        if (hit_sphere(vec3(0, 0, -1), 0.5, r)) {
            return color(1, 0, 0);
        }
    } else if (geometricForm == "triangle") {
        // Triângulo agora virado para baixo e cor vermelha
        vec3 v0(0.5, 0.5, -1.0);
        vec3 v1(-0.5, 0.5, -1.0);
        vec3 v2(0, -0.5, -1.0);

        if (hit_triangle(v0, v1, v2, r)) {
            return color(1, 0, 0); // Vermelho
        }
    } else if (geometricForm == "obj") {
        if (geometricForm == "obj") {
            if (obj_vertices && obj_faces) {
                for (const auto& face : *obj_faces) {
                    const vec3& v0 = (*obj_vertices)[face[0][0]];
                    const vec3& v1 = (*obj_vertices)[face[1][0]];
                    const vec3& v2 = (*obj_vertices)[face[2][0]];

                    if (hit_triangle(v0, v1, v2, r)) {
                        return color(1, 0, 0);
                    }
                }
            }
        }
    }

    // Gradiente de azul para branco
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}


int main() {
    int image_height = 256;
    int image_width = 256;

    // Criar uma instância da classe Gerar_imagem para o círculo
    Gerar_imagem circleImage(image_height, image_width);

    // Definir a origem do raio
    vec3 origin(0, 0, 0);

    // Loop pelos pixels da imagem do círculo
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            // Calcular as coordenadas normalizadas do pixel (-1 a 1)
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);

            // Calcular a direção do raio para o pixel (u, v)
            vec3 direction(u * 2.0 - 1.0, v * 2.0 - 1.0, -1);

            // Criar o raio com a origem e a direção definidas
            ray r(origin, direction);

            // Calcular a cor do pixel para o círculo
            color circle_pixel_color = ray_color(r, "sphere");

            // Converter as cores de float para int (0-255)
            int circler = static_cast<int>(255.999 * circle_pixel_color.x());
            int circleg = static_cast<int>(255.999 * circle_pixel_color.y());
            int circleb = static_cast<int>(255.999 * circle_pixel_color.z());

            // Pintar o pixel na imagem do círculo
            circleImage.Pixel(i, j, circler, circleg, circleb);
        }
    }

    // Salvar a imagem do círculo em um arquivo PNG
    circleImage.Salvar("imagens/circulo.png");

    // Criar uma instância da classe Gerar_imagem para o triângulo
    Gerar_imagem triangleImage(image_height, image_width);

    // Loop pelos pixels da imagem do triângulo
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            // Calcular as coordenadas normalizadas do pixel (-1 a 1)
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);

            // Calcular a direção do raio para o pixel (u, v)
            vec3 direction(u * 2.0 - 1.0, v * 2.0 - 1.0, -1);

            // Criar o raio com a origem e a direção definidas
            ray r(origin, direction);

            // Calcular a cor do pixel para o triângulo
            color triangle_pixel_color = ray_color(r, "triangle");

            // Converter as cores de float para int (0-255)
            int triangler = static_cast<int>(255.999 * triangle_pixel_color.x());
            int triangleg = static_cast<int>(255.999 * triangle_pixel_color.y());
            int triangleb = static_cast<int>(255.999 * triangle_pixel_color.z());

            // Pintar o pixel na imagem do triângulo
            triangleImage.Pixel(i, j, triangler, triangleg, triangleb);
        }
    }

    // Salvar a imagem do triângulo em um arquivo PNG
    triangleImage.Salvar("imagens/triangulo.png");

    // Carregar o modelo do objeto 3D
    ObjectReader objReader;
    objReader.readObj("objetos/cube.obj");

    // Definir a escala desejada para o objeto (por exemplo, reduzir pela metade)
    double scale_factor = 0.5;

    // Aplicar a escala aos vértices do objeto
    for (vec3& vertex : objReader.vertice_list) {
        vertex *= scale_factor;
    }

    std::vector<vec3> objVertices = objReader.vertice_list;
    std::vector<mat3> objFaces = objReader.triangle_list;

    // Criar uma instância da classe Gerar_imagem para o Iron Man
    Gerar_imagem cubeImage(image_height, image_width);

    // Loop pelos pixels da imagem do Iron Man
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            // Calcular as coordenadas normalizadas do pixel (-1 a 1)
            auto u = double(i) / (image_width - 1);
            auto v = double(j) / (image_height - 1);

            // Calcular a direção do raio para o pixel (u, v)
            vec3 direction(u * 2.0 - 1.0, v * 2.0 - 1.0, -1);

            // Criar o raio com a origem e a direção definidas
            ray r(origin, direction);

            // Calcular a cor do pixel para o Iron Man
            color cube_pixel_color = ray_color(r, "obj", &objVertices, &objFaces);

            // Converter as cores de float para int (0-255)
            int cuber = static_cast<int>(255.999 * cube_pixel_color.x());
            int cubeg = static_cast<int>(255.999 * cube_pixel_color.y());
            int cubeb = static_cast<int>(255.999 * cube_pixel_color.z());

            // Pintar o pixel na imagem do Iron Man
            cubeImage.Pixel(i, j, cuber, cubeg, cubeb);
        }
    }

    // Salvar a imagem do Iron Man em um arquivo PNG
    cubeImage.Salvar("imagens/cube.png");

    return 0;
}
