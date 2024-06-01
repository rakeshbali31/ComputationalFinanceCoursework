//
// Created by Rakesh Bali on 17/05/2024.
//

#include <Algorithm.h>
#include <iostream>
#include "Backtest.h"

int main() {
    Backtest backtest;
    if(!backtest.getInputData()) {
        std::cout << "Exiting the program";
        return 0;
    }
    backtest.backtest();
    backtest.displayResults();

    /*std::vector<std::vector<double>> Q = {
        {1.0, 1.0},
        {2.0, 3.0}
    };

    std::vector<double> b = {5, 13};
    std::vector<double> x0(2, 0);
    auto weights = Algorithm::conjugateGradient(Q, b, x0, 1e-9);
    std::cout << weights[0] << " "  << weights[1];*/
}

