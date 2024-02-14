#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;

inline double linear_para_gamma(double componente_linear)
{
    return sqrt(componente_linear);
}

void escrever_cor(std::ostream &out, color cor_pixel, int amostras_por_pixel) {
    auto r = cor_pixel.x();
    auto g = cor_pixel.y();
    auto b = cor_pixel.z();

    auto escala = 1.0 / amostras_por_pixel;
    r *= escala;
    g *= escala;
    b *= escala;

    r = linear_para_gamma(r);
    g = linear_para_gamma(g);
    b = linear_para_gamma(b);

    static const interval intensidade(0.000, 0.999);
    out << static_cast<int>(256 * intensidade.clamp(r)) << ' '
        << static_cast<int>(256 * intensidade.clamp(g)) << ' '
        << static_cast<int>(256 * intensidade.clamp(b)) << '\n';
}

#endif
