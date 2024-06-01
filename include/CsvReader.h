//
// Created by Rakesh Bali on 18/05/2024.
//

#ifndef CSVREADER_H
#define CSVREADER_H

#include <vector>
#include <string>

class CsvReader {
public:
    bool readCsv(const std::string& filename, std::vector<std::vector<double>>& matrix);
};


#endif //CSVREADER_H
