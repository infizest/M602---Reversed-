#include "analyzer.h"
#include <iostream>
#include <limits>

CO2Statistics analyzeData(const std::vector<CO2Data> &data) {
    CO2Statistics stats;
    double totalCO2 = 0;
    double minCO2 = std::numeric_limits<double>::max();
    double maxCO2 = std::numeric_limits<double>::lowest();

    for (const auto &entry : data) {
        totalCO2 += entry.co2_emissions;
        if (entry.co2_emissions < minCO2) {
            minCO2 = entry.co2_emissions;
            stats.minCountry = entry.country;
        }
        if (entry.co2_emissions > maxCO2) {
            maxCO2 = entry.co2_emissions;
            stats.maxCountry = entry.country;
        }
    }

    stats.averageCO2 = totalCO2 / data.size();
    stats.minCO2 = minCO2;
    stats.maxCO2 = maxCO2;
    return stats;
}
