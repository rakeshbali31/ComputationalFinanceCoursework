//
// Created by Rakesh Bali on 18/05/2024.
//
#include "CsvReader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


bool CsvReader::readCsv(const std::string& filename, Matrix& matrix) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        Vector row;

        while (getline(ss, cell, ',')) {
            row.push_back(std::stod(cell));
        }
        matrix.push_back(row);
    }

    file.close();
    return true;
}
