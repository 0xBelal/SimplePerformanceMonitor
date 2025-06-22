//
// Created by Belal on 22-Jun-25.
//

#include "../interface/AlertManager.h"

void AlertManager::notify(const std::string& message) {
    std::cout << "[ALERT] " << message << "\n";
}