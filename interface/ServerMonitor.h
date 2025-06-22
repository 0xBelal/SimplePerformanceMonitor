//
// Created by Belal on 22-Jun-25.
//

#ifndef SERVERMONITOR_H
#define SERVERMONITOR_H
#include <map>
#include <string>
#include <vector>
#include "ServerMetric.h"
#include "AlertManager.h"

class ServerMonitor {
    std::map<std::string, ServerMetric> metrics;

public:
    void addMetric(const std::string& name, int windowSize, int threshold);

    void updateMetric(const std::string& name, int value);
    void simulateFromFile(const std::string& filename);
};


#endif //SERVERMONITOR_H
