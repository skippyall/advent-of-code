#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "common_code_header.hpp"

using namespace std;

vector<string> split(basic_istream<char> &input, char delimiter, bool emptyLine) {
    vector<string> lines;
    string line;
    while(getline(input, line, delimiter)) {
        if(line != ""  || emptyLine) {
            lines.push_back(line);
        }
    }
    return lines;
}

vector<string> split(basic_istream<char> &input, char delimiter) {
    return split(input, delimiter, false);
}

vector<string> splitString(string input, char delimiter, bool emptyLine) {
    stringstream stream(input);
    return split(stream, delimiter, emptyLine);
}

vector<string> splitString(string input, char delimiter) {
    return splitString(input, delimiter, false);
}

vector<string> linesOfFile(string path, bool emptyLine) {
    ifstream input(path);
    if(input.is_open()) {
        return split(input, '\n', emptyLine);
    }
    return vector<string>();
}

vector<string> linesOfFile(string path, bool emptyLine) {
    return linesOfFile(path, false);
}

point::point(int x, int y) {
    this->x = x;
    this->y = y;
}