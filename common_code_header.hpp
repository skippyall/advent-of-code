#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::basic_istream<char> &input, char delimiter);

std::vector<std::string> splitString(std::string input, char delimiter);

std::vector<std::string> linesOfFile(std::string path);

#endif