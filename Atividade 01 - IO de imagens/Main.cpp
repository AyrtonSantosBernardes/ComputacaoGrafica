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

void f_degrade(Gerar_imagem &img) {
    int width = 256, height = 256;
    for (int j = 0; j < height; ++j) {

        for (int i = 0; i < width; ++i) {
            int r = static_cast<int>(255.999 * i / (width - 1));
            int g = static_cast<int>(255.999 * j / (height - 1));
            int b = 0;
            img.Pixel(i, j, r, g, b);
        }
    }
}


void f_arvore(Gerar_imagem &img) {
    int width = 256, height = 256;
    // Desenhar tronco
    for (int j = 0; j < height; ++j) {
        
        for (int i = 0; i < width; ++i) {
            if (i >= width / 2 - 10 && i <= width / 2 + 10 && j >= height / 2) {
                img.Pixel(i, j, 139, 69, 19); // Cor marrom para o tronco
            }
            // Desenhar copa da árvore
            else if ((i - width / 2) * (i - width / 2) + (j - height / 4) * (j - height / 4) <= 10000) {
                img.Pixel(i, j, 34, 139, 34); // Cor verde para a copa
            } else {
                img.Pixel(i, j, 255, 255, 255); // Cor branca para o fundo
            }
        }
    }
}


void f_casa(Gerar_imagem &img) {
    int width = 256, height = 256;
    // Desenhar a estrutura da casa
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            if (i >= width / 4 && i <= 3 * width / 4 && j >= height / 4 && j <= 3 * height / 4) {
                img.Pixel(i, j, 0, 0, 255); // Cor azul para a casa
            }
            // Desenhar o telhado 
            else if (j <= height / 4 && abs(i - width / 2) <= j) {
                img.Pixel(i, j, 255, 0, 0); // Cor vermelha para o telhado
            } else {
                img.Pixel(i, j, 255, 255, 255); // Cor branca para o fundo
            }
        }
    }
}




int main() {
    Gerar_imagem img(256, 256);

    f_degrade(img);
    img.Salvar("degrade.png");

    f_arvore(img);
    img.Salvar("arvore.png");

    f_casa(img);
    img.Salvar("casa.png");

    return 0;
}



