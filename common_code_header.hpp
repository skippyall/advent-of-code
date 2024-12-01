#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(basic_istream<char> &input, char delimiter);

vector<string> splitString(string input, char delimiter);

vector<string> linesOfFile(string path);

#endif