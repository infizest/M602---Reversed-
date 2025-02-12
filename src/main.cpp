#include <iostream>
#include "downloader.h"
#include "parser.h"
#include "analyzer.h"
#include "report_generator.h"

int main() {
    std::string url = "https://raw.githubusercontent.com/owid/co2-data/refs/heads/master/owid-co2-data.csv";  
    std::string filename = "owid-co2-data.csv";

    // Step 1: Download the dataset
    if (downloadCSV(url, filename)) {
        std::cout << "[INFO] CSV file downloaded successfully.\n";
    } else {
        std::cerr << "[ERROR] Failed to download CSV file.\n";
        return 1;
    }

    // Step 2: Parse CSV data
    std::vector<CO2Data> data;
    try {
        data = parseCSV(filename);
    } catch (const std::exception &e) {
        std::cerr << "[ERROR] Failed to parse CSV file: " << e.what() << "\n";
        return 1;
    }

    if (data.empty()) {
        std::cerr << "[ERROR] CSV file is empty or parsing failed.\n";
        return 1;
    }

    // Step 3: Analyze data
    CO2Statistics stats = analyzeData(data);

    // Step 4: Generate report
    if (generateReport(stats, "co2_report.txt")) {
        std::cout << "[INFO] CO2 emissions report generated successfully! Check co2_report.txt\n";
    } else {
        std::cerr << "[ERROR] Failed to generate CO2 emissions report.\n";
        return 1;
    }

    return 0;
}
