#ifndef MAT3_H
#define MAT3_H

#include <cmath>
#include <iostream>

class mat3 {
public:
    double e[3][3];

    mat3() {
        e[0][0] = 1;
        e[0][1] = 0;
        e[0][2] = 0;
        e[1][0] = 0;
        e[1][1] = 1;
        e[1][2] = 0;
        e[2][0] = 0;
        e[2][1] = 0;
        e[2][2] = 1;
    }

    mat3(double e00, double e01, double e02,
         double e10, double e11, double e12,
         double e20, double e21, double e22) {
        e[0][0] = e00; e[0][1] = e01; e[0][2] = e02;
        e[1][0] = e10; e[1][1] = e11; e[1][2] = e12;
        e[2][0] = e20; e[2][1] = e21; e[2][2] = e22;
    }

    double operator()(int i, int j) const { return e[i][j]; }
    double& operator()(int i, int j) { return e[i][j]; }

    mat3 operator+(const mat3 &other) const {
        mat3 result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result(i, j) = e[i][j] + other(i, j);
            }
        }
        return result;
    }

    mat3 operator-(const mat3 &other) const {
        mat3 result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result(i, j) = e[i][j] - other(i, j);
            }
        }
        return result;
    }

    mat3 operator*(const mat3 &other) const {
        mat3 result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result(i, j) = e[i][0] * other(0, j) + e[i][1] * other(1, j) + e[i][2] * other(2, j);
            }
        }
        return result;
    }
};

// Utility functions for mat3

inline std::ostream& operator<<(std::ostream &out, const mat3 &m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            out << m(i, j) << ' ';
        }
        out << '\n';
    }
    return out;
}

#endif
