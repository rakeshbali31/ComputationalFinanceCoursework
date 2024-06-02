#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Matrix.h"

class Algorithm {
public:

    static Vector conjugateGradient(const Matrix& Q, const Vector& b, const Vector& x0, double tolerance);

};

#endif // ALGORITHM_H
