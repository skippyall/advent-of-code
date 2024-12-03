#include <iostream>
#include <string>
#include <vector>
#include "common_code_header.hpp"

int parseFirst(string current, int &index) {
    index += 4;

    cout << "Hi " << current.at(index) << " " << index << "\n";
                
    string number1 = "";
    while(isdigit(current.at(index))) {
        cout << "Append " << current.at(index);
        number1 += current.at(index);
        index++;
    }

    cout << number1 << '\n';
    if(current.at(index) == ',' && number1 != "") {
        cout << "Hi2\n";
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

    for(string line : lines) {
        string current = line;
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

    cout << total;
}