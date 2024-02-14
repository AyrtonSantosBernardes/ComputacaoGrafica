#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "object_reader.h"
#include "src/vec3.h"
#include "src/mat3.h"
#include <vector>


void printVector(const std::string prefix, const std::vector<vec3> &vec3_list) {
    for (const auto& v : vec3_list) {
        std::cout << prefix << " (" << v[0] << ", " << v[1] << ", " << v[2] << ")" << std::endl;
    }
}

void printMat(const std::vector<mat3> &face_list) {
    for (const auto &face : face_list) {
        std::cout << "f (";
        for (int i = 0; i < 3; i++) {
            if (i > 0) std::cout << " ";
            std::cout << face[i][0] << "/" << face[i][1] << "/" << face[i][2];
        }
        std::cout << ")" << std::endl;
    }
}

int main() {
    // Lista de caminhos para os arquivos OBJ
    std::vector<std::string> file_paths = {"objetos/bugatti.obj", "objetos/IronMan.obj"};

    for (const auto& file_path : file_paths) {
        std::cout << "Reading file: " << file_path << std::endl;

        ObjectReader obj_reader;
        obj_reader.readObj(file_path);

        std::cout << "Vertice List:" << std::endl;
        printVector("v", obj_reader.vertice_list);

        std::cout << "Texture List:" << std::endl;
        printVector("vt", obj_reader.texture_list);

        std::cout << "Normal List:" << std::endl;
        printVector("vn", obj_reader.normal_list);

        std::cout << "Triangle List:" << std::endl;
        printMat(obj_reader.triangle_list);

        std::cout << std::endl; 
    }

    return 0;
}