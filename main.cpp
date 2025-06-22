#include "interface/ServerMonitor.h"
#include <iostream>

int main() {
    ServerMonitor monitor;

    monitor.addMetric("RequestRate", 10, 10);
    monitor.addMetric("CPUUsage", 5, 75);


    monitor.simulateFromFile("../data.csv");

    system("pause");
    return 0;
}
