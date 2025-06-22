//
// Created by Belal on 22-Jun-25.
//

#include "../interface/ServerMonitor.h"
#include "../interface/AlertManager.h"
#include <fstream>
#include <sstream>

void ServerMonitor::addMetric(const std::string& name, int windowSize, int threshold) {
    metrics.emplace(name, ServerMetric(name, windowSize, threshold));
}

void ServerMonitor::updateMetric(const std::string& name, int value) {
    if (metrics.find(name) != metrics.end()) {
        metrics[name].update(value);
    }
}
void ServerMonitor::simulateFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "[ERROR] Couldn't open file: " << filename << "\n";
        return;
    }

    std::string line;
    std::getline(file, line);  // read header

    std::vector<std::string> metricNames;
    std::istringstream header(line);
    std::string token;
    std::getline(header, token, ','); // skip timestamp
    while (std::getline(header, token, ',')) {
        metricNames.push_back(token);
    }

    int second = 0;
    while (std::getline(file, line)) {
        second++;
        std::istringstream row(line);
        std::getline(row, token, ','); // skip timestamp

        for (const auto& name : metricNames) {
            if (!std::getline(row, token, ',')) break;

            int value = std::stoi(token);

            auto it = metrics.find(name);
            if (it != metrics.end()) {
                it->second.update(value);
                it->second.printReport(second);
                if (it->second.isOverloaded()) {
                    AlertManager::notify(name + " overload at sec " + std::to_string(second));
                }
            }
        }
    }
}
