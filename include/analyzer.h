#ifndef ANALYZER_H
#define ANALYZER_H

#include <vector>
#include "parser.h"  
struct CO2Statistics {
    double avgEmissions;
    double minEmissions;
    std::string minCountry;
    double maxEmissions;
    std::string maxCountry;
};

// Ensure function signature is correct
CO2Statistics analyzeData(const std::vector<CO2Data> &data);

#endif
