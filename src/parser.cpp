#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<CO2Data> parseCSV(const std::string &filename) {
    std::vector<CO2Data> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Error opening file: " + filename);
    }

    std::string line;
    // Read the header and discard it
    if (std::getline(file, line)) {
        std::cout << "[DEBUG] Skipping header: " << line << std::endl;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string country, yearStr, emissionsStr;

        if (std::getline(ss, country, ',') &&
            std::getline(ss, yearStr, ',') &&
            std::getline(ss, emissionsStr, ',')) {

            try {
                int year = std::stoi(yearStr);
                double emissions = emissionsStr.empty() ? 0.0 : std::stod(emissionsStr);

                // Debug print
                std::cout << "[DEBUG] Parsed: " << country << ", " << year << ", " << emissions << " metric tons" << std::endl;

                data.push_back({country, year, emissions});
            } catch (const std::exception &e) {
                std::cerr << "[ERROR] Skipping invalid line: " << line << " | Error: " << e.what() << std::endl;
            }
        }
    }

    file.close();
    return data;
}
