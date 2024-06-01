#include "PortfolioSolver.h"
#include <Algorithm.h>
#include <AssetCharacteristics.h>


Vector PortfolioSolver::solver() const {
    const int numAssets = assetReturns[0].size();
    const auto means = AssetCharacteristics::calculateMeans(assetReturns, startRow, endRow);
    const auto covariances = AssetCharacteristics::calculateCovariance(assetReturns, means, startRow, endRow);

    // Create the augmented matrices for optimization
    Matrix Q(numAssets + 2, Vector(numAssets + 2, 0.0));
    Vector b(numAssets + 2, 0.0);
    Vector x0(numAssets + 2, 1.0/numAssets); // Initial guess

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

    // Solve using the conjugate gradient method
    auto weights = Algorithm::conjugateGradient(Q, b, x0, 1e-6);
    weights.pop_back(); weights.pop_back(); // Removing lambda and M parameter
    return weights;
}
