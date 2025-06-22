//
// Created by Belal on 22-Jun-25.
//

#ifndef ALERTMANAGER_H
#define ALERTMANAGER_H



#include <string>
#include <iostream>

class AlertManager {
public:
    static void notify(const std::string& message);
};



#endif //ALERTMANAGER_H
