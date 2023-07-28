#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    int finalIdx = 0;
    std::vector<std::string> elves;

    while (std::getline(input, token, '\n')) {
        elves.push_back(token);

        if (elves.size() != 3)
            continue;

        for (const auto &c : elves[0]) {
            int i = elves[1].find(c);
            if (i == std::string::npos)
                continue;

            finalIdx = elves[2].find(elves[1][i]);
            if (finalIdx != std::string::npos)
                break;
        }

        total += GetPriority(elves[2][finalIdx]);
        finalIdx = 0;
        elves.clear();
    }
    
    std::cout << total << std::endl;

    return 0;
}
