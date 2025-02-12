#include "analyzer.h"
#include <iostream>
#include <limits>

void analyzeCO2Emissions(const std::vector<CO2Data> &data) {
    if (data.empty()) {
        std::cerr << "[ERROR] No data available for analysis." << std::endl;
        return;
    }

    double totalEmissions = 0.0;
    double minEmissions = std::numeric_limits<double>::max();
    double maxEmissions = std::numeric_limits<double>::lowest();
    std::string minCountry, maxCountry;
    
    std::cout << "\n=== Debugging Emission Values ===\n";

    for (const auto &entry : data) {
        std::cout << "Country: " << entry.country << ", Year: " << entry.year << ", CO2: " << entry.co2_emissions << " metric tons\n";

        totalEmissions += entry.co2_emissions;
        if (entry.co2_emissions < minEmissions) {
            minEmissions = entry.co2_emissions;
            minCountry = entry.country;
        }
        if (entry.co2_emissions > maxEmissions) {
            maxEmissions = entry.co2_emissions;
            maxCountry = entry.country;
        }
    }

    double avgEmissions = totalEmissions / data.size();

    std::cout << "\n=== CO2 Emissions Report ===" << std::endl;
    std::cout << "Average CO2 Emissions: " << avgEmissions << " metric tons" << std::endl;
    std::cout << "Lowest CO2 Emissions: " << minEmissions << " (Country: " << minCountry << ")" << std::endl;
    std::cout << "Highest CO2 Emissions: " << maxEmissions << " (Country: " << maxCountry << ")" << std::endl;
}
