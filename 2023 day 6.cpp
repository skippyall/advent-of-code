#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<string> splitAndFilter(string input) {
    vector<string> output;
    stringstream stream(input);
    char del = ' ';

    string text;
    bool first = true;
    while(getline (stream, text, del)) {
        if(text != "") {
            if(first) {
                first = false;
            } else {
                output.push_back(text);
            }
        }
    }
    return output;
}

long calculatePossibilities(long time, long record) {
    long possibilities = 0;
    for(long pressTime = 0; pressTime < time; pressTime++) {
        long distance = pressTime * (time - pressTime);
        if(distance > record) {
            possibilities++;
        }
    }
    return possibilities;
}

int main() {
    cout << "Hi\n";
    string path;
    cin >> path;

    ifstream input (path);

    if(input.is_open()) {
        string text;

        cout << "\n";

        string timestr;
        getline (input, timestr);
        string recordstr;
        getline (input, recordstr);

        cout << timestr << "\n";
        cout << recordstr << "\n";

        input.close();

        vector<string> times = splitAndFilter(timestr);
        vector<string> records = splitAndFilter(recordstr);

        long total = 1;

        for(int i = 0; i < times.size(); i++) {
            long time = stol(times.at(i));
            long record = stol(records.at(i));
            total = total * calculatePossibilities(time, record);
        }
        cout << total << "\n";

        cout << "\n";
    }
}