//
// Created by Rakesh Bali on 23/05/2024.
//

#ifndef BACKTEST_H
#define BACKTEST_H
#include <PortfolioSolver.h>

class Backtest: public PortfolioSolver {
private:
    int out_of_sample_period;
    Vector target_returns;
    Matrix out_of_sample_returns;
    Matrix out_of_sample_variance;

public:
    Backtest() : out_of_sample_period(10) {} // Default constructor initializing all members.
    Backtest(int out_of_sample_period, const Vector& target_returns) : out_of_sample_period(out_of_sample_period), target_returns(target_returns){}
    void backtest();
    int getInputData();
    void displayResults() const;
    void saveResultsToCSV(const std::string& filename) const;
};
#endif //BACKTEST_H
