//
// Created by Rakesh Bali on 23/05/2024.
//
#include "Backtest.h"

#include <Algorithm.h>
#include <AssetCharacteristics.h>
#include <CsvReader.h>
#include <iostream>

void Backtest::backtest() {
    int num_of_days = getAssetReturns().size();
    int in_sample_period = getEndRow() - getStartRow();
    for (auto target_return:target_returns) {
        setRange(0, in_sample_period);
        int start = getStartRow(), end = getEndRow();
        std::vector<double> portfolioReturns;    // Local variable to store the portfolio returns for this target return
        std::vector<double> portfolioVariances;  // Local variable to store the portfolio variances for this target return
        setTargetReturn(target_return);
        while(end < num_of_days) {
            std::vector<double> weights = solver();

            std::vector<double> meanReturns = AssetCharacteristics::calculateMeans(getAssetReturns(), end, end+out_of_sample_period);
            double portfolioReturn = Algorithm::dot(weights,meanReturns);
            portfolioReturns.push_back(portfolioReturn);

            std::vector<std::vector<double>> covariance = AssetCharacteristics::calculateCovariance(getAssetReturns(), meanReturns, end, end+out_of_sample_period);
            double portfolioVariance = Algorithm::dot(weights, Algorithm::multiply(covariance, weights));
            portfolioVariances.push_back(portfolioVariance);

            end += out_of_sample_period;
            start += out_of_sample_period;
            setRange(start, end);
        }
        out_of_sample_returns.push_back(portfolioReturns);
        out_of_sample_variance.push_back(portfolioVariances);
    }

}

int Backtest::getInputData() {
    std::string filename;
    int in_sample_period;

    //std::cout << "Enter the name of the excel file: "; std::cin >> filename;
    CsvReader reader;
    std::vector<std::vector<double>> matrix;
    bool success = reader.readCsv("asset_returns.csv", matrix);
    if (!success) {
        std::cerr << "Failed to read the CSV file." << std::endl;
        return 0;
    }

    //std::cout << "Enter the target return: "; std::cin >> targetReturn;
    double start=0.0, end=0.1, step=0.005;

    // for (double value = start; value <= end; value += step) {
    //     target_returns.push_back(value);
    // }

    target_returns.push_back(0.095);

    std::cout << "Enter the insample period: "; std::cin >> in_sample_period;
    std::cout << "Enter the outsample period: "; std::cin >> out_of_sample_period;

    // Now set the values in PortfolioSolver
    setAssetReturns(matrix);
    setRange(0, in_sample_period);
    return 1;
}


void Backtest::displayResults() const {
    for(int i=0; i<target_returns.size(); ++i) {
        std::cout << "Printing results for target return :: " << target_returns[i] << std::endl << std::endl;

        std::vector<double> returns = out_of_sample_returns[i];
        std::vector<double> varinaces = out_of_sample_variance[i];
        int array_size = returns.size();
        for(int j=0; j<array_size; ++j) {
            std::cout << "Period " << j+1 << "  " << returns[j] << " " << varinaces[j] << std::endl;
        }
        std::cout << std::endl;
    }
}



