#include <iostream>
#include <vector>
#include <string>
#include "../common_code_header.hpp"

void trace(std::vector<point> &points, point current) {
    
}

int main() {
    std::string path;
    std::cin >> path;

    std::vector<std::string> lines = linesOfFile(path);

    int total = 0;

    for(int y = 0; y < lines.size(); y++) {
        std::string line = lines.at(y);
        for(int x = 0; x < line.size(); x++) {
            if(line.at(x) == '0') {
                std::vector<point> points = std::vector<point>();
                trace(points, point(x, y));
            }
        }
    }
}