#include "cleaner.h"
#include <algorithm>
#include <cctype>

Cleaner::Cleaner() {}

std::vector<std::vector<std::string>> Cleaner::cleanData(const std::vector<std::vector<std::string>>& rawData) {
    std::vector<std::vector<std::string>> cleanedData;
    for (const auto& row : rawData) {
        if (isValidRow(row)) {
            cleanedData.push_back(trimSpaces(row));
        }
    }
    return cleanedData;
}

bool Cleaner::isValidRow(const std::vector<std::string>& row) {
    for (const auto& field : row) {
        if (field.empty()) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> Cleaner::trimSpaces(const std::vector<std::string>& row) {
    std::vector<std::string> trimmedRow = row;
    for (auto& field : trimmedRow) {
        field.erase(field.begin(), std::find_if(field.begin(), field.end(), [](unsigned char ch) { return !std::isspace(ch); }));
        field.erase(std::find_if(field.rbegin(), field.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), field.end());
    }
    return trimmedRow;
}
