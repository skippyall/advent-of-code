#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "../common_code_header.hpp"


class Range {
    public:

    Range(long start, long end) {
        this->start = start;
        this->end = end;
    }

    long start;
    long end;

    bool isInRange(long num) {
        return num >= start && num <= end;
    }
};

int main() {
    std::string path;
    std::cin >> path;

    bool over = true;

    std::vector<std::string> lines = linesOfFile(path, true);
    std::vector<Range> ranges;
    long long count = 0;

    for(int i = 0; i < lines.size(); i++) {
        std::string line = lines.at(i);

        if(line == "") {
            over = false;
        } else if(over) {
            std::vector<std::string> split = splitString(line, '-', false);
            if(split.size() < 2) {
                std::cout << line;
            }
            long from = stol(split.at(0));
            long to = stol(split.at(1));

            ranges.push_back(Range(from, to));
        } else {
            long number = stol(line);

            for(int z = 0; z < ranges.size(); z++) {
                if(ranges.at(z).isInRange(number)) {
                    count++;
                    break;
                }
            }
        }
    }
    std::cout << count;
}