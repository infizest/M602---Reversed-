#ifndef CLEANER_H
#define CLEANER_H

#include <vector>
#include <string>

class Cleaner {
public:
    Cleaner();
    std::vector<std::vector<std::string>> cleanData(const std::vector<std::vector<std::string>>& rawData);
    
private:
    bool isValidRow(const std::vector<std::string>& row);
    std::vector<std::string> trimSpaces(const std::vector<std::string>& row);
};

#endif 