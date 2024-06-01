#ifndef ASSET_CHARACTERISTICS_H
#define ASSET_CHARACTERISTICS_H

#include <Matrix.h>
#include <vector>

class AssetCharacteristics {
public:
    static Vector calculateMeans(const Matrix& returns, int startRow, int endRow);
    static Matrix calculateCovariance(const Matrix& returns, const Vector& means, int startRow, int endRow);
};

#endif // ASSET_CHARACTERISTICS_H
