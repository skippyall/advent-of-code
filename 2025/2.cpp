#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "../common_code_header.hpp"


int main() {
    std::string path;
    std::cin >> path;

    std::vector<std::string> lines = linesOfFile(path);
    std::string line = lines.at(0);

    std::vector<std::string> ranges = splitString(line, ',');

    unsigned long long sum = 0;

    for(int r = 0; r < ranges.size(); r++) {
        std::string range = ranges.at(r);
        std::vector<std::string> borders = splitString(range, '-');
        long start = stol(borders.at(0));
        long end = stol(borders.at(1));
        std::cout << start << '|' << end << std::endl;
        for(long i = start; i <= end; i++) {
            std::string id = std::to_string(i);
            bool invalid = false;
            if(id.size() % 2 == 1) {
                continue;
            }

            long m = id.size() / 2;
                
                
            std::string before = id.substr(0, m);
            std::string after = id.substr(m, m);

            std::cout << id << '|' << before << ':' << after << std::endl;
            if(before == after) {
                sum += i;
                invalid = true;
                std::cout << "invalid" << std::endl;
            }
            
        }
    }

    std::cout << sum;
}