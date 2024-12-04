#include <iostream>
#include <vector>
#include <string>
#include "../common_code_header.hpp"

bool match(int index, std::vector<std::string> &lines, int x, int y, int dx, int dy) {
    std::string toMatch = "MAS";
    x += dx;
    y += dy;
    if(x < 0 || y < 0 || y >= lines.size() || x >= lines.at(y).size()) {
        return false;
    }

    if(toMatch.at(index) == lines.at(y).at(x)) {
        if(index < 2) {
            return match(index + 1, lines, x, y, dx, dy);
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int main() {
    std::string path;
    std::cin >> path;

    std::vector<std::string> lines = linesOfFile(path);
    int directions[8][2] = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };

    int total = 0;

    for(int y = 0; y < lines.size(); y++) {
        std::string line = lines.at(y);
        for(int x = 0; x < line.size(); x++) {
            char c = line.at(x);
            if(c == 'X') {
                for(int d = 0; d < 8; d++) {
                    if(match(0, lines, x, y, directions[d][0], directions[d][1])) {
                        total++;
                    }
                }
            }
        }
    }

    std::cout << total << "\n";
}