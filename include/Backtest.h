//
// Created by Rakesh Bali on 23/05/2024.
//

#ifndef BACKTEST_H
#define BACKTEST_H
#include <PortfolioSolver.h>

class Backtest: public PortfolioSolver {
private:
    int out_of_sample_period;
    std::vector<double> target_returns;
    std::vector<std::vector<double>> out_of_sample_returns;
    std::vector<std::vector<double>> out_of_sample_variance;

public:
    Backtest() : out_of_sample_period(10) {} // Default constructor initializing all members.
    Backtest(int out_of_sample_period, const std::vector<double>& target_returns) : out_of_sample_period(out_of_sample_period), target_returns(target_returns){}
    void backtest();
    int getInputData();
    void displayResults() const;
    void verifyResults();

};
#endif //BACKTEST_H
