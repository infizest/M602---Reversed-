#ifndef ANALYZER_H
#define ANALYZER_H

#include "parser.h"

struct CO2Statistics {
    double averageCO2;
    double minCO2;
    std::string minCountry;
    double maxCO2;
    std::string maxCountry;
};

CO2Statistics analyzeData(const std::vector<CO2Data> &data);

#endif
