using namespace std;
#include "wp.h"

vector<double> wp(uint T, uint P, ifstream &inputFile) {
    string line;
    // Skipping First Line
    getline(inputFile, line, '\n');

    vector<int> W(T, 0);
    vector<int> Q(T, 0);

    while (getline(inputFile, line,'\n')) {
        stringstream ss(line);
        int date, winner, wpoints, loser, lpoints;
        char c;

        ss >> date >> winner >> wpoints >> loser >> lpoints;
        int widx = winner - 1;
        int lidx = loser - 1;
        W[widx-1] = W[widx-1] + 1; 
        Q[widx-1] = Q[widx-1] + 1; 
        Q[lidx-1] = Q[lidx-1] + 1; 
    }

    vector<double> r(T, 0);
    for (int i = 0; i < T; i++) {
        r[i] = W[i]/Q[i];
    }
    return r;
}