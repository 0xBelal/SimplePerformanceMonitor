//
// Created by Belal on 22-Jun-25.
//

#include "../interface/ServerMetric.h"
#include <iostream>

ServerMetric::ServerMetric(const std::string& name, int windowSize, int threshold)
    : name(name), window(windowSize), threshold(threshold) {}

ServerMetric::ServerMetric(): name(""),window(0), threshold(0) {
}

void ServerMetric::update(int value) {
    window.add(value);
}

bool ServerMetric::isOverloaded() const {
    return window.getAverage() > threshold;
}

void ServerMetric::printReport(int second) const {
    std::cout << "[Sec " << second << "] " << name << " Avg: " << window.getAverage();
    if (isOverloaded()) std::cout << "  [Overloaded]";
    std::cout << "\n";
}