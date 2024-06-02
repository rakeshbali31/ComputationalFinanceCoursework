//
// Created by Rakesh Bali on 19/05/2024.
//

#include "Algorithm.h"


// Function to implement the conjugate gradient algorithm
Vector Algorithm::conjugateGradient(const Matrix& Q, const Vector& b, const Vector& x0, double tolerance) {
    Vector x = x0;
    Vector r = b - (Q * x); // Using operator- for subtraction
    Vector p = r;
    double rsold = r ^ r; // Using operator^ for dot product

    for (size_t i = 0; i < b.size(); ++i) {
        Vector Qp = Q * p;
        double alpha = rsold / (p ^ Qp); // Using operator^ for dot product
        x = x + (alpha * p); // Using operator+ for addition and operator* for scalar multiplication
        r = r - (alpha * Qp); // Using operator- for subtraction and operator* for scalar multiplication
        double rsnew = r ^ r; // Using operator^ for dot product

        if (sqrt(rsnew) < tolerance)
            break;

        double beta = rsnew / rsold;
        p = r + (beta * p); // Using operator+ for addition and operator* for scalar multiplication
        rsold = rsnew;
    }
    return x;
}

