//
// Created by Rakesh Bali on 19/05/2024.
//

#include "Algorithm.h"

std::vector<double> Algorithm::multiply(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vec) {
    std::vector<double> result(vec.size(), 0.0);
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            result[i] += matrix[i][j] * vec[j];
        }
    }
    return result;
}

double Algorithm::dot(const std::vector<double>& a, const std::vector<double>& b) {
    double result = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }
    return result;
}

std::vector<double> Algorithm::add(const std::vector<double>& a, const std::vector<double>& b) {
    std::vector<double> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] + b[i];
    }
    return result;
}

std::vector<double> Algorithm::subtract(const std::vector<double>& a, const std::vector<double>& b) {
    std::vector<double> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] - b[i];
    }
    return result;
}

std::vector<double> Algorithm::scalarMultiply(double scalar, const std::vector<double>& vec) {
    std::vector<double> result(vec.size());
    for (size_t i = 0; i < vec.size(); ++i) {
        result[i] = scalar * vec[i];
    }
    return result;
}

std::vector<double> Algorithm::conjugateGradient(const std::vector<std::vector<double>>& Q, const std::vector<double>& b, const std::vector<double>& x0, double tolerance) {
    std::vector<double> x = x0;
    std::vector<double> r = subtract(b, multiply(Q, x));
    std::vector<double> p = r;
    double rsold = dot(r, r);

    for (size_t i = 0; i < b.size(); ++i) {
        std::vector<double> Qp = multiply(Q, p);
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

