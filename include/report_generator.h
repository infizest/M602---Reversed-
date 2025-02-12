#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include <string>
#include "analyzer.h"

bool generateReport(const CO2Statistics &stats, const std::string &outputFile); // Change from void to bool

#endif
