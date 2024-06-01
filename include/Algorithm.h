#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <cmath>

class Algorithm {
public:
    static std::vector<double> conjugateGradient(const std::vector<std::vector<double>>& Q, const std::vector<double>& b, const std::vector<double>& x0, double tolerance);
    static std::vector<double> multiply(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vec);
    static double dot(const std::vector<double>& a, const std::vector<double>& b);
    static std::vector<double> add(const std::vector<double>& a, const std::vector<double>& b);
    static std::vector<double> subtract(const std::vector<double>& a, const std::vector<double>& b);
    static std::vector<double> scalarMultiply(double scalar, const std::vector<double>& vec);

};

#endif // ALGORITHM_H
