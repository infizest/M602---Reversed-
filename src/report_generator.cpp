#include "report_generator.h"
#include <fstream>
#include <iostream>

void generateReport(const CO2Statistics &stats, const std::string &outputFile) {
    std::ofstream file(outputFile);

    if (!file) {
        std::cerr << "Error creating report file!\n";
        return;
    }

    file << "=== CO2 Emissions Report ===\n";
    file << "Average CO2 Emissions: " << stats.averageCO2 << " metric tons\n";
    file << "Lowest CO2 Emissions: " << stats.minCO2 << " (Country: " << stats.minCountry << ")\n";
    file << "Highest CO2 Emissions: " << stats.maxCO2 << " (Country: " << stats.maxCountry << ")\n";
    
    std::cout << "Report saved to " << outputFile << "\n";
    file.close();
}
