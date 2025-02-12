#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

struct CO2Data {
    std::string country;
    int year;
    double co2_emissions;
};

std::vector<CO2Data> parseCSV(const std::string &filename);

#endif
