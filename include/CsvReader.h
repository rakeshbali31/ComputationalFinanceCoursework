//
// Created by Rakesh Bali on 18/05/2024.
//

#ifndef CSVREADER_H
#define CSVREADER_H

#include <Matrix.h>
#include <string>

class CsvReader {
public:
    static bool readCsv(const std::string& filename, Matrix& matrix);
};


#endif //CSVREADER_H
