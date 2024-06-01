#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Matrix.h"

class Algorithm {
public:

    static Vector conjugateGradient(const Matrix& Q, const Vector& b, const Vector& x0, double tolerance);
    static Vector multiply(const Matrix& matrix, const Vector& vec);
    static double dot(const Vector& a, const Vector& b);
    static Vector add(const Vector& a, const Vector& b);
    static Vector subtract(const Vector& a, const Vector& b);
    static Vector scalarMultiply(double scalar, const Vector& vec);

};

#endif // ALGORITHM_H
