#include <iostream>
#include <cassert>
#include "../include/vec2.h"
#include "../include/vec3.h"
#include "../include/vec4.h"
#include "../include/mat2.h"
#include "../include/mat3.h"
#include "../include/mat4.h"

// Função para comparar floats com tolerância
bool isEqual(float a, float b, float tolerance = 0.001) {
    return fabs(a - b) < tolerance;
}

// Testes para a classe vec2
void testVec2() {
    // Teste de construtor e operações básicas
    vec2 v1(1, 2);
    vec2 v2(3, 4);
    
    assert(v1.x() == 1);
    assert(v1.y() == 2);
    assert(v1[0] == 1);
    assert(v1[1] == 2);
    
    // Teste de adição
    vec2 sum = v1 + v2;
    assert(sum.x() == 4);
    assert(sum.y() == 6);
}

// Testes para a classe vec3
void testVec3() {
    // Teste de construtor e operações básicas
    vec3 v1(1, 2, 3);
    vec3 v2(4, 5, 6);
    
    assert(v1.x() == 1);
    assert(v1.y() == 2);
    assert(v1.z() == 3);
    assert(v1[0] == 1);
    assert(v1[1] == 2);
    assert(v1[2] == 3);
    
    // Teste de adição
    vec3 sum = v1 + v2;
    assert(sum.x() == 5);
    assert(sum.y() == 7);
    assert(sum.z() == 9);
}

// Testes para a classe vec4
void testVec4() {
    // Teste de construtor e operações básicas
    vec4 v1(1, 2, 3, 4);
    vec4 v2(5, 6, 7, 8);
    
    assert(v1.x() == 1);
    assert(v1.y() == 2);
    assert(v1.z() == 3);
    assert(v1.w() == 4);
    assert(v1[0] == 1);
    assert(v1[1] == 2);
    assert(v1[2] == 3);
    assert(v1[3] == 4);
    
    // Teste de adição
    vec4 sum = v1 + v2;
    assert(sum.x() == 6);
    assert(sum.y() == 8);
    assert(sum.z() == 10);
    assert(sum.w() == 12);
}

// Testes para a classe mat2
void testMat2() {
    // Teste de construtor e operações básicas
    mat2 m1(1, 2, 3, 4);
    mat2 m2(5, 6, 7, 8);
    
    assert(m1(0, 0) == 1);
    assert(m1(0, 1) == 2);
    assert(m1(1, 0) == 3);
    assert(m1(1, 1) == 4);
    
    // Teste de multiplicação
    mat2 product = m1 * m2;
    assert(product(0, 0) == 19);
    assert(product(0, 1) == 22);
    assert(product(1, 0) == 43);
    assert(product(1, 1) == 50);
}

// Testes para a classe mat3
void testMat3() {
    // Teste de construtor e operações básicas
    mat3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    mat3 m2(9, 8, 7, 6, 5, 4, 3, 2, 1);
    
    assert(m1(0, 0) == 1);
    assert(m1(0, 1) == 2);
    assert(m1(0, 2) == 3);
    assert(m1(1, 0) == 4);
    assert(m1(1, 1) == 5);
    assert(m1(1, 2) == 6);
    assert(m1(2, 0) == 7);
    assert(m1(2, 1) == 8);
    assert(m1(2, 2) == 9);
    
    // Teste de multiplicação
    mat3 product = m1 * m2;
    assert(product(0, 0) == 30);
    assert(product(0, 1) == 24);
    assert(product(0, 2) == 18);
    assert(product(1, 0) == 84);
    assert(product(1, 1) == 69);
    assert(product(1, 2) == 54);
    assert(product(2, 0) == 138);
    assert(product(2, 1) == 114);
    assert(product(2, 2) == 90);
}

void testMat4() {
    // Teste de construtor e operações básicas
    mat4 m1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    mat4 m2(16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
    
    assert(m1(0, 0) == 1);
    assert(m1(0, 1) == 2);
    assert(m1(0, 2) == 3);
    assert(m1(0, 3) == 4);
    assert(m1(1, 0) == 5);
    assert(m1(1, 1) == 6);
    assert(m1(1, 2) == 7);
    assert(m1(1, 3) == 8);
    assert(m1(2, 0) == 9);
    assert(m1(2, 1) == 10);
    assert(m1(2, 2) == 11);
    assert(m1(2, 3) == 12);
    assert(m1(3, 0) == 13);
    assert(m1(3, 1) == 14);
    assert(m1(3, 2) == 15);
    assert(m1(3, 3) == 16);
    
    // Teste de multiplicação
    mat4 product = m1 * m2;

    assert(product(0, 0) == 80);
    assert(product(0, 1) == 70);
    assert(product(0, 2) == 60);
    assert(product(0, 3) == 50);
    assert(product(1, 0) == 240);
    assert(product(1, 1) == 214);
    assert(product(1, 2) == 188);
    assert(product(1, 3) == 162);
    assert(product(2, 0) == 400);
    assert(product(2, 1) == 358);
    assert(product(2, 2) == 316);
    assert(product(2, 3) == 274);
    assert(product(3, 0) == 560);
    assert(product(3, 1) == 502);
    assert(product(3, 2) == 444);
    assert(product(3, 3) == 386);
}

int main() {
    // Executar os testes
    testVec2();
    testVec3();
    testVec4();
    testMat2();
    testMat3();
    testMat4();
    
    std::cout << "Todos os testes passaram!" << std::endl;
    
    return 0;
}
