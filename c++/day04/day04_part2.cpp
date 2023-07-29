#include <iostream>
#include <fstream>
#include <string>

int IsRangeContained(const std::string &firstRange, const std::string &secondRange) {
    int fIdx = firstRange.find('-');
    int sIdx = secondRange.find('-');
    int f1 = std::stoi(firstRange.substr(0, fIdx));
    int f2 = std::stoi(firstRange.substr(fIdx + 1, firstRange.size() - 1));
    int s1 = std::stoi(secondRange.substr(0, sIdx));
    int s2 = std::stoi(secondRange.substr(sIdx + 1, secondRange.size() - 1));
    int isContained = 0;

    if (f1 > s2 || f2 < s1)
        isContained = 0;
    else
        isContained = 1;

    std::cout << firstRange << ", " << secondRange << " -> " << isContained << '\n';

    return isContained;
}

int main() {
    std::ifstream input("./puzzle_input");
    std::string pair;
    std::string range;
    int total = 0;

    while(std::getline(input, pair, '\n')) {
        int commaIdx = pair.find(',');
        std::string first = pair.substr(0, commaIdx);
        std::string second = pair.substr(commaIdx + 1, pair.size() - 1);

        total += IsRangeContained(first, second);
    }


    auto i = (std::stoi("41") < std::stoi("40")) ? 1 : 0;
    std::cout << i << '\n';
    std::cout << total << '\n';

    return 0;
}
