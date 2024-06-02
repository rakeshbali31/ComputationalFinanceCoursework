//
// Created by Rakesh Bali on 23/05/2024.
//
#include "Backtest.h"
#include <Algorithm.h>
#include <AssetCharacteristics.h>
#include <CsvReader.h>
#include <iomanip>
#include <iostream>
#include <fstream>


void Backtest::backtest() {
    const int num_of_days = getAssetReturns().size();
    const int in_sample_period = getEndRow() - getStartRow();

    for (const auto target_return:target_returns) {
        setRange(0, in_sample_period);
        int start = getStartRow(), end = getEndRow();
        Vector portfolioReturns;    // Local variable to store the portfolio returns for this target return
        Vector portfolioVariances;  // Local variable to store the portfolio variances for this target return
        setTargetReturn(target_return);
        while(end < num_of_days) {
            Vector weights = solver();

            Vector meanReturns = AssetCharacteristics::calculateMeans(getAssetReturns(), end, end+out_of_sample_period);
            double portfolioReturn = weights ^ meanReturns;
            portfolioReturns.push_back(portfolioReturn);

            Matrix covariance = AssetCharacteristics::calculateCovariance(getAssetReturns(), meanReturns, end, end+out_of_sample_period);
            double portfolioVariance = weights ^ (covariance * weights);
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
    Matrix matrix;
    const bool success = reader.readCsv("asset_returns.csv", matrix);
    if (!success) {
        std::cerr << "Failed to read the CSV file." << std::endl;
        return 0;
    }

    //std::cout << "Enter the target return: "; std::cin >> targetReturn;
    double start=0.0, end=0.1, step=0.005;
    for (double value = start; value <= end; value += step) {
        target_returns.push_back(value);
    }

    std::cout << "Enter the insample period: "; std::cin >> in_sample_period;
    std::cout << "Enter the outsample period: "; std::cin >> out_of_sample_period;

    // Now set the values in PortfolioSolver
    setAssetReturns(matrix);
    setRange(0, in_sample_period);
    return 1;
}


void Backtest::displayResults() const {

    for (int i = 0; i < target_returns.size(); ++i) {
        std::cout << "Printing results for target return :: " << std::fixed << std::setprecision(3) << target_returns[i] << std::endl << std::endl;

        Vector returns = out_of_sample_returns[i];
        Vector variances = out_of_sample_variance[i];
        const int array_size = returns.size();

        // Print header
        std::cout << std::setw(10) << "Period" << std::setw(20) << "Mean Return" << std::setw(20) << "Variance" << std::endl;

        for (int j = 0; j < array_size; ++j) {
            // Print data for each period
            std::cout << std::setw(10) << j + 1 << std::setw(20) << std::fixed << std::setprecision(10) << returns[j] << std::setw(20) << variances[j] << std::endl;
        }
        std::cout << std::endl;
    }
}


void Backtest::saveResultsToCSV(const std::string& filename) const {
    std::ofstream outFile(filename);

    for (int i = 0; i < target_returns.size(); ++i) {
        Vector returns = out_of_sample_returns[i];
        Vector variances = out_of_sample_variance[i];
        const int array_size = returns.size();

        // Write header to file
        outFile << "Period,Mean_Return,Variance,Target_Return\n";

        for (int j = 0; j < array_size; ++j) {
            // Write data for each period to file
            outFile << (j + 1) << "," << returns[j] << "," << variances[j] << "," << target_returns[i] << "\n";
        }
        outFile << "\n";
    }
    outFile.close();
}



