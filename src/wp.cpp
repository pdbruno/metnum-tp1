using namespace std;
#include "wp.h"

vector<double> wp(uint T, uint P, ifstream &inputFile) {
    string line;
    getline(inputFile, line, '\n');

    vector<int> Wins(T, 0);
    vector<int> GamesPlayed(T, 0);

    while (getline(inputFile, line, '\n')) {
        stringstream ss(line);
        int date, team1, points1, team2, points2, winner, loser;

        ss >> date >> team1 >> points1 >> team2 >> points2;

        if (points1 > points2) {
            winner = team1 - 1;
            loser = team2 - 1;
        }
        else {
            winner = team2 - 1;
            loser = team1 - 1;
        }

        Wins[winner]++;
        GamesPlayed[winner]++;
        GamesPlayed[loser]++;
    }

    vector<double> r(T, 0);

    for (int i = 0; i < T; i++) {
        r[i] = (double)Wins[i]/(double)GamesPlayed[i];
    }    
    return r;
}