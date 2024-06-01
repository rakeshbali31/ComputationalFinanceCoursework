//
// Created by Rakesh Bali on 19/05/2024.
//

#include "Algorithm.h"

Vector Algorithm::multiply(const Matrix& matrix, const Vector& vec) {
    Vector result(vec.size(), 0.0);
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            result[i] += matrix[i][j] * vec[j];
        }
    }
    return result;
}

double Algorithm::dot(const Vector& a, const Vector& b) {
    double result = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }
    return result;
}

Vector Algorithm::add(const Vector& a, const Vector& b) {
    Vector result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] + b[i];
    }
    return result;
}

Vector Algorithm::subtract(const Vector& a, const Vector& b) {
    Vector result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] - b[i];
    }
    return result;
}

Vector Algorithm::scalarMultiply(double scalar, const Vector& vec) {
    Vector result(vec.size());
    for (size_t i = 0; i < vec.size(); ++i) {
        result[i] = scalar * vec[i];
    }
    return result;
}

Vector Algorithm::conjugateGradient(const Matrix& Q, const Vector& b, const Vector& x0, double tolerance) {
    Vector x = x0;
    Vector r = subtract(b, multiply(Q, x));
    Vector p = r;
    double rsold = dot(r, r);

    for (size_t i = 0; i < b.size(); ++i) {
        Vector Qp = multiply(Q, p);
        double alpha = rsold / dot(p, Qp);
        x = add(x, scalarMultiply(alpha, p));
        r = subtract(r, scalarMultiply(alpha, Qp));
        double rsnew = dot(r, r);

        if (sqrt(rsnew) < tolerance)
            break;

        double beta = rsnew / rsold;
        p = add(r, scalarMultiply(beta, p));
        rsold = rsnew;
    }
    return x;
}

