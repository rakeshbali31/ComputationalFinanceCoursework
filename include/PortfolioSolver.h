#ifndef PORTFOLIOSOLVER_H
#define PORTFOLIOSOLVER_H

#include <Matrix.h>

class PortfolioSolver {
private:
    Matrix assetReturns; // Stores returns of various assets within a specified range.
    double targetReturn; // Target return for the portfolio.
    int startRow;        // Starting index of the row in asset returns data.
    int endRow;          // Ending index of the row in asset returns data.

public:
    // Constructors
    PortfolioSolver() : targetReturn(0.0), startRow(0), endRow(0) {} // Default constructor initializing all members.
    explicit PortfolioSolver(const Matrix& matrix, double target, int start, int end)
        : assetReturns(matrix), targetReturn(target), startRow(start), endRow(end) {}
    // Constructor to initialize all properties.

    // Setters
    void setAssetReturns(const Matrix& matrix) { assetReturns = matrix; }
    void setTargetReturn(double target) { targetReturn = target; }
    void setRange(int start, int end) { startRow = start; endRow = end; }

    // Getters
    const Matrix& getAssetReturns() const { return assetReturns; }
    double getTargetReturn() const { return targetReturn; }
    int getStartRow() const { return startRow; }
    int getEndRow() const { return endRow; }

    // Solver
    Vector solver() const;
};

#endif // PORTFOLIOSOLVER_H
