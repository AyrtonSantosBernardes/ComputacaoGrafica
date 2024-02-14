#ifndef MAT2_H
#define MAT2_H

#include <cmath>
#include <iostream>

class mat2 {
public:
    double e[2][2];

    mat2() {
        e[0][0] = 1;
        e[0][1] = 0;
        e[1][0] = 0;
        e[1][1] = 1;
    }

    mat2(double e00, double e01, double e10, double e11) {
        e[0][0] = e00;
        e[0][1] = e01;
        e[1][0] = e10;
        e[1][1] = e11;
    }

    double operator()(int i, int j) const { return e[i][j]; }
    double& operator()(int i, int j) { return e[i][j]; }

    mat2 operator+(const mat2 &other) const {
        mat2 result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result(i, j) = e[i][j] + other(i, j);
            }
        }
        return result;
    }

    mat2 operator-(const mat2 &other) const {
        mat2 result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result(i, j) = e[i][j] - other(i, j);
            }
        }
        return result;
    }

    mat2 operator*(const mat2 &other) const {
        mat2 result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result(i, j) = e[i][0] * other(0, j) + e[i][1] * other(1, j);
            }
        }
        return result;
    }
};

// Utility functions for mat2

inline std::ostream& operator<<(std::ostream &out, const mat2 &m) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            out << m(i, j) << ' ';
        }
        out << '\n';
    }
    return out;
}

#endif
