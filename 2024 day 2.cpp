#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include "common_code_header.hpp"

using namespace std;

bool isSafe(string input) {
	vector<string> values = splitString(input, ' ');
        int lastnumber;
        bool increasing;
        for(int i = 0; i < values.size(); i++) {
        	string value = values.at(i);
        	int number = stoi(value);
            if(i != 0) {
            	int difference = lastnumber - number;
                int absdifference = abs(difference);
                if(absdifference == 0 || absdifference > 3) {
                	return false;	
                }
                bool currentIncreasing = difference < 0;
                if(i == 1) {
                	increasing = currentIncreasing;
                } else {
                	if(increasing != currentIncreasing) {
                    	return false;
                    }
                }
            }
            lastnumber = number;
        }
        return true;
}

int main() {
	string path;
    cin >> path;
	vector<string> lines = linesOfFile(path);
    int total = 0;
    
    for(string input : lines) {
    	
        if(isSafe(input)) {
        	total++;
        }
        
    }
    
    cout << "Total: " << total;
}