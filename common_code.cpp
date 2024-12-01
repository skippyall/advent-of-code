#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

#include "common_code_header.hpp"

using namespace std;

vector<string> split(basic_istream<char> &input, char delimiter) {
    vector<string> lines;
    string line;
    while(getline(input, line, delimiter)) {
        if(line != "") {
            lines.push_back(line);
        }
    }
    return lines;
}

vector<string> splitString(string input, char delimiter) {
    stringstream stream(input);
    return split(stream, delimiter);
}

vector<string> linesOfFile(string path) {
    ifstream input(path);
    if(input.is_open()) {
        return split(input, '\n');
    }
    return vector<string>();
}