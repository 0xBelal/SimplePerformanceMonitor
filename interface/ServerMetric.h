//
// Created by Belal on 22-Jun-25.
//

#ifndef SERVERMETRIC_H
#define SERVERMETRIC_H

#

#include <string>
#include "SlidingWindow.h"

class ServerMetric {
    std::string name;
    SlidingWindow window;
    int threshold;

public:
    ServerMetric(const std::string& name, int windowSize, int threshold);
    ServerMetric();
    void update(int value);
    bool isOverloaded() const;
    void printReport(int second) const;
};


#endif //SERVERMETRIC_H
