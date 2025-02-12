#include "downloader.h"
#include <iostream>
#include <fstream>
#include <curl/curl.h>

// Callback function for writing received data
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    std::ofstream *outFile = static_cast<std::ofstream*>(userp);
    outFile->write(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}

bool downloadCSV(const std::string &url, const std::string &filename) {
    CURL *curl;
    CURLcode res;
    std::ofstream outFile(filename, std::ios::binary);

    if (!outFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }

    curl = curl_easy_init();
    if (!curl) {
        std::cerr << "cURL initialization failed!\n";
        return false;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outFile);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    outFile.close();

    return res == CURLE_OK;
}
