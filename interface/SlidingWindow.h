//
// Created by Belal on 22-Jun-25.
//

#ifndef SLIDINGWINDOW_H
#define SLIDINGWINDOW_H

#include <vector>

class SlidingWindow {
    int size;
    int total = 0;
    int current_index = 0;
    std::vector<int> buffer;

public:
    SlidingWindow(int size);
    void add(int value);
    double getAverage() const;
    int getTotal() const;
};

#endif //SLIDINGWINDOW_H
