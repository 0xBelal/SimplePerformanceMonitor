//
// Created by Belal on 22-Jun-25.
//

#include "../interface/SlidingWindow.h"

SlidingWindow::SlidingWindow(int size) : size(size), buffer(size, 0) {}

void SlidingWindow::add(int value) {
    total -= buffer[current_index];
    buffer[current_index] = value;
    total += value;
    current_index = (current_index + 1) % size;
}

double SlidingWindow::getAverage() const {
    return static_cast<double>(total) / size;
}

int SlidingWindow::getTotal() const {
    return total;
}