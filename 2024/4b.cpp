#include <iostream>
#include <vector>
#include <string>
#include "../common_code_header.hpp"

const int directions[4][2] = {
    {-1, -1},
    {-1, 1},
    {1, 1},
    {1, -1}
};

bool directionMatch(std::vector<std::string> &lines, char toMatch, int x, int y, int dx, int dy) {
    x += dx;
    y += dy;
    if(x < 0 || y < 0 || y >= lines.size() || x >= lines.at(y).size()) {
        return false;
    }

    return (toMatch == lines.at(y).at(x));
}

bool match(std::vector<std::string> &lines, int x, int y, int d) {
    std::string toMatch = "MMSS";
    for(int i = 0; i < 4; i++) {
        int direction = (i + d) % 4;
        if(!directionMatch(lines, toMatch.at(i), x, y, directions[direction][0], directions[direction][1])) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string path;
    std::cin >> path;

    std::vector<std::string> lines = linesOfFile(path);
    

    int total = 0;

    for(int y = 0; y < lines.size(); y++) {
        std::string line = lines.at(y);
        for(int x = 0; x < line.size(); x++) {
            char c = line.at(x);
            if(c == 'A') {
                for(int d = 0; d < 4; d++) {
                    if(match(lines, x, y, d)) {
                        total++;
                    }
                }
            }
        }
    }

    std::cout << total << "\n";
}