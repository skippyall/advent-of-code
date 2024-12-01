#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "common_code_header.hpp"

using namespace std;

void insert(list<int> &v, int value) {
    if(v.empty() || v.back() <= value) {
        v.push_back(value);
    }
    list<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++) {
        if(*it > value) {
            v.insert(it, value);
            return;
        } 
    }

    cout << "Did not insert value " << value << "\n";
}

int main() {
    cout << "Hi\n";
    string path;
    cin >> path;
    vector<string> lines = linesOfFile(path);
    cout << lines.size() << "\n";
    list<int> values1;
    list<int> values2;
    for(string line : lines) {
        vector<string> values = splitString(line, ' ');
        insert(values1, stoi(values.at(0)));
        insert(values2, stoi(values.at(1)));

        cout << line << " " << values.at(0) << " " << stoi(values.at(0)) << " " << values.at(1) << " " << stoi(values.at(1)) << "\n";
    }

    cout << "Größen";
    cout << values1.size() << " " << values2.size() << "\n\n";

    list<int>::iterator it1 = values1.begin();
    list<int>::iterator it2 = values2.begin();

    int total = 0;

    while(it1 != values1.end() && it2 != values2.end()) {
        int difference = *it1 - *it2;
        if(difference < 0) {
            difference = difference * -1;
        }

        total += difference;

        //cout << *it1 << " " << *it2 << " " << difference << " " << total << "\n";

        it1++;
        it2++;
    }

    cout << "Ergebnis:\n";
    cout << total << "\n";
}