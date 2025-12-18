
#pragma once
#include <iostream>
#include <limits>
#include <string>

inline int readInt(const std::string& prompt, int minV, int maxV) {
    while (true) {
        std::cout << prompt;
        int x;
        if (std::cin >> x && x >= minV && x <= maxV) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return x;
        }
        std::cout << "Invalid input. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

inline std::string readLine(const std::string& prompt) {
    std::cout << prompt;
    std::string s;
    std::getline(std::cin, s);
    while (s.empty()) {
        std::cout << "Cannot be empty.\n" << prompt;
        std::getline(std::cin, s);
    }
    return s;
}
