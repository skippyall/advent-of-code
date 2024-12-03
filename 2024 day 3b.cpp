#include <iostream>
#include <string>
#include <vector>
#include "common_code_header.hpp"

int parseFirst(string current, int &index) {
    index += 4;

    cout << "Hi " << current.at(index) << " " << index << "\n";
                
    string number1 = "";
    while(isdigit(current.at(index))) {
        number1 += current.at(index);
        index++;
    }

    if(current.at(index) == ',' && number1 != "") {
        index++;

        string number2 = "";
        while(isdigit(current.at(index))) {
            number2 += current.at(index);
            index++;
        }
        if(current.at(index) == ')' && number2 != "") {
            index++;
            cout << number1 << " " << number2 << "\n";
            return stoi(number1) * stoi(number2);
        }
    }
    return false;
}

int main() {
    string path;
    cin >> path;
    vector<string> lines = linesOfFile(path);

    int total = 0;

    bool enabled = true;

    for(string line : lines) {
        string current = line;
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
            cout << mulindex << " " << doindex << " " << dontindex << " ";
            if(mulindex < doindex && mulindex < dontindex && mulindex != current.npos && enabled) {
                index = mulindex;
                total += parseFirst(current, index);
                cout << "mul";
            } else if (doindex < mulindex && doindex < dontindex && doindex != current.npos){
                index = doindex;
                index += 4;
                enabled = true;
                cout << "enabled";
            } else if (dontindex < mulindex && dontindex < doindex && dontindex != current.npos){
                index = dontindex;
                index += 7;
                enabled = false;
                cout << "disabled";
            }

            if((mulindex == 2147483647 || !enabled) && doindex == 2147483647 && dontindex == 2147483647) {
                current = "";
            }
            
            cout << '\n';
            if(current != "") {
                current = current.substr(index, current.size() - 1);
            }
        }
    }

    cout << total;
}