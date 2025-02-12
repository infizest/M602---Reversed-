#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<CO2Data> parseCSV(const std::string &filename) {
    std::vector<CO2Data> data;
    std::ifstream file(filename);
    std::string line, country, year, co2;

    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        return data;
    }

    // Skip the header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, country, ',');
        std::getline(ss, year, ',');
        std::getline(ss, co2, ',');

        if (!country.empty() && !year.empty() && !co2.empty()) {
            CO2Data entry;
            entry.country = country;
            entry.year = std::stoi(year);
            entry.co2_emissions = std::stod(co2);
            data.push_back(entry);
        }
    }

    return data;
}
