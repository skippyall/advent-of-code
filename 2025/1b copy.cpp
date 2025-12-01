#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "../common_code_header.hpp"


int main() {

    std::cout << -21 % 7 << std::endl;
    std::string path;
    std::cin >> path;

    std::vector<std::string> lines = linesOfFile(path);

    int dial = 50;
    int count = 0;

    for(int i = 0; i < lines.size(); i++) {
        std::string line = lines.at(i);

        int value = stoi(line.substr(1));

        for(int c = 1; c <= value; c++) {
            if(line.at(0) == 'R') {
                if((dial + c) % 100 == 0) {
                    std::cout << "Finde " << i << std::endl;
                    count++;
                }
            } else {
                if((dial - c) % 100 == 0) {
                    std::cout << "Finde " << i << " rückwärts" << std::endl;
                    count++;
                }
            }
        }

        if(line.substr(0, 1) == "L") {
            value = value * -1;
        }
        

        dial = (dial + value) % 100;
        std::cout << dial << std::endl;
    }

    std::cout << count;
}