using namespace std;

#include "cmm.h"

vector<double> cmm(uint T, uint P, ifstream &inputFile) {
    // Initialize the matrix as a n x n array of 0.
    vector<vector<int>> C = vector<vector<int> >(T, vector<int>(T,0));
    vector<int> B(T, 0);

    // Set the diagonal to be 2s
    for(unsigned int t = 0; t < T; t++)
        C[t][t] = 2;

    string line;
    // Skipping First Line
    getline(inputFile, line, '\n');

    while (getline(inputFile, line,'\n')) {
        stringstream ss(line);
        int date, winner, wpoints, loser, lpoints;
        char c;

        ss >> date >> winner >> wpoints >> loser >> lpoints;
        C[winner][loser] = C[winner][loser] - 1;
        C[loser][winner] = C[loser][winner] - 1;
        C[loser][loser] = C[loser][loser] + 1;
        C[winner][winner] = C[winner][winner] + 1;
        B[winner] = B[winner] + 1;
        B[loser] = B[loser] - 1;
    }


    vector<double> r;
    r.push_back(2.0);
    return r;
}   