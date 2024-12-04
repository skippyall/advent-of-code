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
    return false;
}

int main() {
    std::string path;
    std::cin >> path;
    std::vector<std::string> lines = linesOfFile(path);

    int total = 0;

    for(std::string line : lines) {
        std::string current = line;
        while (current != ""){
            int index = current.find("mul(");
            if(index != current.npos) {
                total += parseFirst(current, index);
                current = current.substr(index, current.size() - 1);
            } else {
                current = "";
            }

        }
    }

    std::cout << total;
}