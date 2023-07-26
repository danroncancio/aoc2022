#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int GetRoundPoints(const std::string &round) {
    std::stringstream ss(round);
    std::string token;
    std::vector<int> moves;
    int roundPoints = 0;
    int movePoints = 0;

    while(getline(ss, token, ' ')) {
        int m;
        if (token == "A" || token == "X")
            m = 1;
        else if (token == "B" || token == "Y")
            m = 2;
        else
            m = 3;

        moves.push_back(m);
    }

    if (moves[1] == 2) {
        roundPoints = 3;
        movePoints = moves[0];
    } else if (moves[1] == 1) {
        roundPoints = 0;
        movePoints = ((moves[0] + 1) % 3) + 1;
    } else {
        roundPoints = 6;
        movePoints = (moves[0] % 3) + 1;
    }

    return (roundPoints + movePoints);
}

int main() {
    std::string round;
    int total = 0;

    std::ifstream input("./puzzle_input");
    while(getline(input, round, '\n')) {
        total += GetRoundPoints(round);
    }

    std::cout << total << std::endl;

    return 0;
}
