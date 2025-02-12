#include "analyzer.h"
#include <iostream>
#include <limits>

CO2Statistics analyzeData(const std::vector<CO2Data>& data) {
    if (data.empty()) {
        std::cerr << "[ERROR] No data available for analysis." << std::endl;
        return {0, 0, "N/A", 0, "N/A"};
    }

    double totalEmissions = 0.0;
    double minEmissions = std::numeric_limits<double>::max();
    double maxEmissions = std::numeric_limits<double>::lowest();
    std::string minCountry, maxCountry;

    for (const auto& entry : data) {
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

    return {avgEmissions, minEmissions, minCountry, maxEmissions, maxCountry};
}
