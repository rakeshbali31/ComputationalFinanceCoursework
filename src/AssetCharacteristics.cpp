#include "AssetCharacteristics.h"

using Vector = std::vector<double>;
using Matrix = std::vector<Vector>;

Vector AssetCharacteristics::calculateMeans(const Matrix& returns, int startRow, int endRow) {
    int numAssets = returns[0].size();
    Vector means(numAssets, 0.0);

    for (int i = 0; i < numAssets; ++i) {
        for (int k = startRow; k < endRow; ++k) {
            means[i] += returns[k][i];
        }
        means[i] /= (endRow - startRow);
    }
    return means;
}

Matrix AssetCharacteristics::calculateCovariance(const Matrix& returns, const Vector& means, int startRow, int endRow) {
    int numAssets = returns[0].size();
    Matrix covariance(numAssets, Vector(numAssets, 0.0));

    for (int i = 0; i < numAssets; ++i) {
        for (int j = i; j < numAssets; ++j) {  // Start from i to fill the upper triangle
            double sum = 0.0;
            for (int k = startRow; k < endRow; ++k) {
                double diff_i = returns[k][i] - means[i];
                double diff_j = returns[k][j] - means[j];
                sum += diff_i * diff_j;
            }
            covariance[i][j] = sum / (endRow - startRow - 1);  // Using N-1 (sample covariance) adjust if needed
            covariance[j][i] = covariance[i][j];  // Symmetric matrix
        }
    }

    return covariance;
}
