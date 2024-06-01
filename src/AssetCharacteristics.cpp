#include "AssetCharacteristics.h"

std::vector<double> AssetCharacteristics::calculateMeans(const std::vector<std::vector<double>>& returns, int startRow, int endRow) {
    int numAssets = returns[0].size();
    std::vector<double> means(numAssets, 0.0);

    for (int i = 0; i < numAssets; ++i) {
        for (int k = startRow; k < endRow; ++k) {
            means[i] += returns[k][i];
        }
        means[i] /= (endRow - startRow);
    }

    return means;
}

std::vector<std::vector<double>> AssetCharacteristics::calculateCovariance(const std::vector<std::vector<double>>& returns, const std::vector<double>& means, int startRow, int endRow) {
    int numAssets = returns[0].size();
    std::vector<std::vector<double>> covariance(numAssets, std::vector<double>(numAssets, 0.0));

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
