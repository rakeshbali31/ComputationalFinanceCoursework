//
// Created by Rakesh Bali on 17/05/2024.
//
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
    backtest.saveResultsToCSV("results1.csv");

}

