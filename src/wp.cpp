using namespace std;
#include "wp.h"

vector<double> wp(uint T, uint P, ifstream &inputFile) {
    string line;
    // Skipping First Line
    getline(inputFile, line, '\n');

    while (getline(inputFile, line,'\n')) {
        stringstream ss(line);
        int date, winner, wpoints, loser, lpoints;
        char c;

        ss >> date >> winner >> wpoints >> loser >> lpoints;
    }


    vector<double> r;
    r.push_back(2.0);
    return r;
}