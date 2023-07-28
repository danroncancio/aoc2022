#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

// Using ASCII code values
int GetPriority(const char c) {
    int numValue = (int)c;
    int priority = 0;
    if (numValue < 'a')
        priority = c - 'A' + 27;
    else
        priority = c - 'a' + 1;

    return priority;
}

int main() {
    std::ifstream input("./puzzle_input");
    std::string token;
    int total = 0;

    while (std::getline(input, token, '\n')) {
        int itemIndex = 0;
        int comparmentSize = token.size() / 2;
        std::string first = token.substr(0, comparmentSize);
        std::string second = token.substr(comparmentSize, comparmentSize * 2);

        for (const auto &c : first) {
            itemIndex = second.find(c);
            if (itemIndex != std::string::npos)
                break;
        }

        total += GetPriority(second[itemIndex]);
    }
    
    std::cout << total << std::endl;

    return 0;
}
