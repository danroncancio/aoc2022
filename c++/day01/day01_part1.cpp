#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file_in("./puzzle_input");
    std::string token;
    int acc = 0;
    int mostCalories = 0;

    while (std::getline(file_in, token, '\n')) {
        if (token != "")
            acc += std::stoi(token);
        else if (token == "") {
            if (acc > mostCalories) {
                mostCalories = acc;
            }
            acc = 0;
        }
    }

    std::cout << mostCalories << std::endl;

    return 0;
}
