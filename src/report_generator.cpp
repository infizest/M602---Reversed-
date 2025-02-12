#include "report_generator.h"
#include <fstream>
#include <iostream>

bool generateReport(const CO2Statistics &stats, const std::string &filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "[ERROR] Could not open file for writing: " << filename << "\n";
        return false;
    }

    file << "=== CO2 Emissions Report ===\n";
    file << "Average CO2 Emissions: " << stats.avgEmissions << " metric tons\n";
    file << "Lowest CO2 Emissions: " << stats.minEmissions << " (Country: " << stats.minCountry << ")\n";
    file << "Highest CO2 Emissions: " << stats.maxEmissions << " (Country: " << stats.maxCountry << ")\n";

    file.close();
    return true;
}
