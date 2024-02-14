#include <iostream>
#include <string>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

class Gerar_imagem {
public:
    Gerar_imagem(int width, int height) : width(width), height(height) {
        pixels = new uint8_t[width * height * 3];
    }

    ~Gerar_imagem() {
        delete[] pixels;
    }

    void Pixel(int x, int y, int r, int g, int b) {
        int index = (y * width + x) * 3;
        pixels[index] = static_cast<uint8_t>(r);
        pixels[index + 1] = static_cast<uint8_t>(g);
        pixels[index + 2] = static_cast<uint8_t>(b);
    }

    void Salvar(const std::string &filename) {
        stbi_write_png(filename.c_str(), width, height, 3, pixels, width * 3);
    }

private:
    int width, height;
    uint8_t *pixels;
};