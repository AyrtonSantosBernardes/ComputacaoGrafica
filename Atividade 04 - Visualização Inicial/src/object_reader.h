#ifndef OBJ_READER_H
#define OBJ_READER_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "vec3.h"
#include "mat3.h"

class ObjectReader {
public:
    std::vector<vec3> vertice_list;
    std::vector<vec3> normal_list;
    std::vector<vec3> texture_list;
    std::vector<mat3> triangle_list;

    void parseLine(const std::string &line) {
        if (line.compare(0, 2, "v ") == 0) {
            std::istringstream iss(line.substr(2));
            vec3 vertex;
            iss >> vertex[0] >> vertex[1] >> vertex[2];
            vertice_list.push_back(vertex);
        } else if (line.compare(0, 3, "vt ") == 0) {
            std::istringstream iss(line.substr(3));
            vec3 texture;
            iss >> texture[0] >> texture[1] >> texture[2];
            texture_list.push_back(texture);
        } else if (line.compare(0, 3, "vn ") == 0) {
            std::istringstream iss(line.substr(3));
            vec3 normal;
            iss >> normal[0] >> normal[1] >> normal[2];
            normal_list.push_back(normal);
        } else if (line.compare(0, 2, "f ") == 0) {
            std::istringstream iss(line.substr(2));
            mat3 face;
            vec3 &vertex = face[0];
            for (int i = 0; i < 3; i++) {
                vec3 vec;
                char slash;
                iss >> vec[0] >> slash >> vec[1] >> slash >> vec[2];
                face[i] = vec;
            }
            triangle_list.push_back(face);
        }
    }

    void readObj(std::string file_path) {
        std::ifstream file(file_path);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                parseLine(line);
            }
            file.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo: " << file_path << std::endl;
            exit(1);
        }
    }

    void translate(const vec3& translation) {
        for (auto& vertex : vertice_list) {
            vertex += translation;
        }
    }

    void shift_object(const vec3& shift) {
        for (int i = 0; i < vertice_list.size(); i++) {
            vertice_list[i] += shift;
        }
        for (int i = 0; i < normal_list.size(); i++) {
            normal_list[i] += shift;
        }
        for (int i = 0; i < texture_list.size(); i++) {
            texture_list[i] += shift;
        }
        for (int i = 0; i < triangle_list.size(); i++) {
            triangle_list[i][0] += shift;
            triangle_list[i][1] += shift;
            triangle_list[i][2] += shift;
        }        
    }
};

#endif
