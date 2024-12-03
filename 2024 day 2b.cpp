#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include "common_code_header.hpp"

using namespace std;

bool isSafe(vector<int> numbers) {
        int lastnumber;
        bool increasing;
        for(int i = 0; i < numbers.size(); i++) {
            int number = numbers.at(i);
            cout << number << " ";
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
        cout << "\n";
        return true;
}

bool isSafeDampener(string input) {
    vector<string> inputs = splitString(input, ' ');
    vector<int> numbers;
    for(string input : inputs) {
        numbers.push_back(stoi(input));
    }

    int size = numbers.size();

    for(int i = -1; i < size; i++) {
        vector<int> copy = vector<int>(numbers);
        if(i >= 0) {
            copy.erase(copy.begin() + i);
            cout << "Hi ";
        }
        cout << "Hi2";
        if(isSafe(copy)) {
            return true;
        }
    }
    return false;
}

int main() {
	string path;
    cin >> path;
	vector<string> lines = linesOfFile(path);
    int total = 0;
    
    for(string input : lines) {
    	
        if(isSafeDampener(input)) {
        	total++;
        }
        
    }
    
    cout << "Total: " << total << "\n";
}