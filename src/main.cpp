#include <iostream>


int main() {
    std::string url = "https://raw.githubusercontent.com/owid/co2-data/refs/heads/master/owid-co2-data.csv";  
    std::string filename = "owid-co2-data.csv";

    // Step 1: Download the dataset
    if (downloadCSV(url, filename)) {
        std::cout << "CSV file downloaded successfully.\n";
    } else {
        std::cerr << "Failed to download CSV file.\n";
        return 1;
    }

    // Step 2: Parse CSV data
    std::vector<CO2Data> data = parseCSV(filename);
    if (data.empty()) {
        std::cerr << "Failed to parse CSV file or file is empty.\n";
        return 1;
    }

    // Step 3: Analyze data
    CO2Statistics stats = analyzeData(data);
    
    // Step 4: Generate report
    generateReport(stats, "co2_report.txt");

    std::cout << "CO2 emissions report generated successfully!\n";
    return 0;
}