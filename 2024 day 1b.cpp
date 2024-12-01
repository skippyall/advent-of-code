#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "common_code_header.hpp"

using namespace std;

int main() {
    cout << "Hi\n";
    string path;
    cin >> path;
    vector<string> lines = linesOfFile(path);
    cout << lines.size() << "\n";
    vector<int> values1;
    multiset<int> values2;
    for(string line : lines) {
        vector<string> values = splitString(line, ' ');
        values1.push_back(stoi(values.at(0)));
        values2.insert(stoi(values.at(1)));

        cout << line << " " << values.at(0) << " " << stoi(values.at(0)) << " " << values.at(1) << " " << stoi(values.at(1)) << "\n";
    }

    int total = 0;

    for(int value1 : values1) {
        total += value1 * values2.count(value1);
    }

    cout << "Ergebnis:\n";
    cout << total << "\n";
}