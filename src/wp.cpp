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
        int date, team1, points1, team2, points2, winner, loser;

        ss >> date >> team1 >> points1 >> team2 >> points2;

        if (points1 > points2) {
            winner = team1-1;
            loser = team2-1;
        }
        else {
            winner = team2-1;
            loser = team1-1;
        }

        W[winner] = W[winner] + 1; 
        Q[winner] = Q[winner] + 1; 
        Q[loser] = Q[loser] + 1; 
    }

    vector<double> r(T, 0);
    for (int i = 0; i < T; i++) {
        r[i] = W[i]/Q[i];
    }
    return r;
}