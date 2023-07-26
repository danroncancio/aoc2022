#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file_in("./puzzle_input.txt");
    std::string token;
    int acc = 0;
    int total = 0;
    std::vector<int> calories;

    while (std::getline(file_in, token, '\n')) {
        if (token != "")
            acc += std::stoi(token);
        else if (token == "") {
            calories.push_back(acc);
            acc = 0;
        }
    }

    std::sort(calories.begin(), calories.end(), std::greater<int>());
    for (auto i = 0; i < 3; i++) {
        total += calories[i];
    }

    std::cout << total << "\n";

    return 0;
}
