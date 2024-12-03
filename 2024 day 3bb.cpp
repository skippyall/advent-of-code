#include <iostream>
#include <string>
#include <vector>
#include "common_code_header.hpp"

int parseFirst(std::string current, int &index) {
    index += 4;

    std::cout << "Hi " << current.at(index) << " " << index << "\n";
                
    std::string number1 = "";
    while(isdigit(current.at(index))) {
        std::cout << "Append " << current.at(index);
        number1 += current.at(index);
        index++;
    }

    std::cout << number1 << '\n';
    if(current.at(index) == ',' && number1 != "") {
        std::cout << "Hi2\n";
        index++;

        std::string number2 = "";
        while(isdigit(current.at(index))) {
            number2 += current.at(index);
            index++;
        }
        if(current.at(index) == ')' && number2 != "") {
            index++;
            std::cout << number1 << " " << number2 << "\n";
            return stoi(number1) * stoi(number2);
        }
    }
    return 0;
}

int main() {
    std::string path;
    std::cin >> path;
    std::vector<std::string> lines = linesOfFile(path);

    int total = 0;
    bool enabled = true;

    for(std::string line : lines) {
        std::string current = line;
        while (current != ""){
            if(enabled) {
                int disableIndex = current.find("don't()");
                int index = current.find("mul(");
                
                if(disableIndex < index && disableIndex != std::string::npos) {
                    enabled = false;
                    current = current.substr(disableIndex + 7, current.size() - 1);
                } else {
                    if(index != current.npos) {
                        total += parseFirst(current, index);
                        current = current.substr(index, current.size() - 1);
                    } else {
                        current = "";
                    }
                }
            } else {
                int enableIndex = current.find("do()");
                if(enableIndex != current.npos) {
                    enabled = true;
                    current = current.substr(enableIndex + 4, current.size() - 1);
                } else {
                    current = "";
                }
            }
        }
    }

    std::cout << total;
}