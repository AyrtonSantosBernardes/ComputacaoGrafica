#ifndef MAT4_H
#define MAT4_H

#include <cmath>
#include <iostream>

class mat4 {
public:
    double e[4][4];

    mat4() {
        e[0][0] = 1; e[0][1] = 0; e[0][2] = 0; e[0][3] = 0;
        e[1][0] = 0; e[1][1] = 1; e[1][2] = 0; e[1][3] = 0;
        e[2][0] = 0; e[2][1] = 0; e[2][2] = 1; e[2][3] = 0;
        e[3][0] = 0; e[3][1] = 0; e[3][2] = 0; e[3][3] = 1;
    }

    mat4(double e00, double e01, double e02, double e03,
         double e10, double e11, double e12, double e13,
         double e20, double e21, double e22, double e23,
         double e30, double e31, double e32, double e33) {
        e[0][0] = e00; e[0][1] = e01; e[0][2] = e02; e[0][3] = e03;
        e[1][0] = e10; e[1][1] = e11; e[1][2] = e12; e[1][3] = e13;
        e[2][0] = e20; e[2][1] = e21; e[2][2] = e22; e[2][3] = e23;
        e[3][0] = e30; e[3][1] = e31; e[3][2] = e32; e[3][3] = e33;
    }

    double operator()(int i, int j) const { return e[i][j]; }
    double& operator()(int i, int j) { return e[i][j]; }

    mat4 operator+(const mat4 &other) const {
        mat4 result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result(i, j) = e[i][j] + other(i, j);
            }
        }
        return result;
    }

    mat4 operator-(const mat4 &other) const {
        mat4 result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result(i, j) = e[i][j] - other(i, j);
            }
        }
        return result;
    }

    mat4 operator*(const mat4 &other) const {
        mat4 result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result(i, j) = 0;
                for (int k = 0; k < 4; ++k) {
                    result(i, j) += e[i][k] * other(k, j);
                }
            }
        }
        return result;
    }

};

// Utility functions for mat4

inline std::ostream& operator<<(std::ostream &out, const mat4 &m) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            out << m(i, j) << ' ';
        }
        out << '\n';
    }
    return out;
}

#endif
