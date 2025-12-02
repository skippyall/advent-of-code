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
        //std::cout << start << '|' << end << std::endl;
        for(long i = start; i <= end; i++) {
            std::string id = std::to_string(i);
            bool invalid = false;

            for(long divisor = 2; divisor <= id.length() && !invalid; divisor++) {
                if(id.length() % divisor == 0) {
                    long m = id.size() / divisor;

                    std::string l0 = id.substr(0, m);

                    bool valid = false;

                    for(int l = 1; l < divisor; l++) {
                        std::string after = id.substr(m * l, m);

                        //std::cout << id << '|' << l0 << ':' << after << std::endl;
                        if(l0 != after) {
                            valid = true;
                        }
                    }
                    
                    if(!valid) {
                        invalid = true;
                        sum += i;
                        //std::cout << "invalid" << std::endl;
                    }
                }
            }
            
        }
    }

    std::cout << sum;
}