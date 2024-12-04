#include <iostream>
#include <string>
#include <vector>
#include "common_code_header.hpp"

using namespace std;

int parseFirst(std::string current, int &index) {
    index += 4;
                
    std::string number1 = "";
    while(isdigit(current.at(index))) {
        number1 += current.at(index);
        index++;
    }

    if(current.at(index) == ',' && number1 != "") {
        index++;

        std::string number2 = "";
        while(isdigit(current.at(index))) {
            number2 += current.at(index);
            index++;
        }
        if(current.at(index) == ')' && number2 != "") {
            index++;
            return stoi(number1) * stoi(number2);
        }
    }
    return false;
}

int main() {
    std::string path;
    std::cin >> path;
    std::vector<std::string> lines = linesOfFile(path);

    long total = 0;

    bool enabled = true;

    for(std::string line : lines) {
        std::string current = line;
        while (current != ""){
            int mulindex = current.find("mul(");
            int doindex = current.find("do()");
            int dontindex = current.find("don't()");
            if(mulindex == current.npos || mulindex < 0) {
                mulindex = 2147483647;
            }

            if(doindex == current.npos || doindex < 0) {
                doindex = 2147483647;
            }

            if(dontindex == current.npos || dontindex < 0) {
                dontindex = 2147483647;
            }

            int index;
            std::cout << mulindex << " " << doindex << " " << dontindex << " ";
            if(mulindex < doindex && mulindex < dontindex && mulindex != current.npos && enabled) {
                index = mulindex;
                total += parseFirst(current, index);
                std::cout << "mul " << total;
            } else if (doindex < mulindex && doindex < dontindex && doindex != current.npos){
                index = doindex;
                index += 4;
                enabled = true;
                std::cout << "enabled";
            } else if (dontindex < mulindex && dontindex < doindex && dontindex != current.npos){
                index = dontindex;
                index += 7;
                enabled = false;
                std::cout << "disabled";
            }

            if((mulindex == 2147483647 || !enabled) && doindex == 2147483647 && dontindex == 2147483647) {
                current = "";
            }
            
            std::cout << '\n';
            if(current != "") {
                current = current.substr(index, current.size() - 1);
            }
        }
    }

    std::cout << total;
}