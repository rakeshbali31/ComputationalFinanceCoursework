#ifndef ASSET_CHARACTERISTICS_H
#define ASSET_CHARACTERISTICS_H

#include <vector>

class AssetCharacteristics {
public:
    static std::vector<double> calculateMeans(const std::vector<std::vector<double>>& returns, int startRow, int endRow);
    static std::vector<std::vector<double>> calculateCovariance(const std::vector<std::vector<double>>& returns, const std::vector<double>& means, int startRow, int endRow);
};

#endif // ASSET_CHARACTERISTICS_H
