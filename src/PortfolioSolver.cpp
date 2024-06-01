#include "PortfolioSolver.h"

#include <Algorithm.h>
#include <AssetCharacteristics.h>
#include <iostream>
#include <vector>

std::vector<double> PortfolioSolver::solver() const {
    int numAssets = assetReturns[0].size();
    auto means = AssetCharacteristics::calculateMeans(assetReturns, startRow, endRow);
    auto covariances = AssetCharacteristics::calculateCovariance(assetReturns, means, startRow, endRow);

    // Create the augmented matrices for optimization
    std::vector<std::vector<double>> Q(numAssets + 2, std::vector<double>(numAssets + 2, 0.0));
    std::vector<double> b(numAssets + 2, 0.0);
    std::vector<double> x0(numAssets + 2, 0.1); // Initial guess

    // Fill Q and b based on the model
    for (int i = 0; i < numAssets; ++i) {
        for (int j = 0; j < numAssets; ++j) {
            Q[i][j] = covariances[i][j];
        }
        Q[i][numAssets] = -means[i];
        Q[i][numAssets + 1] = -1;

        Q[numAssets][i] = -means[i];
        Q[numAssets + 1][i] = -1;
    }
    b[numAssets] = -targetReturn;
    b[numAssets + 1] = -1;

    // Solve using the conjugate gradient method (or any other suitable method)
    auto weights = Algorithm::conjugateGradient(Q, b, x0, 1e-6);
    weights.pop_back(); weights.pop_back(); // Removing lambda and M parameter
    return weights;
}
