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

    int dial = 50;
    int count = 0;

    for(int i = 0; i < lines.size(); i++) {
        std::string line = lines.at(i);

        int value = stoi(line.substr(1));

        if(line.substr(0, 1) == "L") {
            count = count + abs(floor((dial -value) / 100.0));
        } else {
            count = count + abs(floor((value + dial) / 100.0));
        }

        if(line.at(0) == 'L') {
            value = value * -1;
        }
        
        
        dial = (dial + value) % 100;
        if(dial < 0) {
            dial = dial + 100;
        }
    }

    std::cout << count;
}