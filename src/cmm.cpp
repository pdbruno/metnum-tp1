using namespace std;

#include "cmm.h"

vector<double> cmm(uint T, uint P, ifstream &inputFile)
{
    // Initialize the matrix as a n x n array of 0.
    vector<vector<double>> C = vector<vector<double>>(T, vector<double>(T, 0));
    vector<double> B(T, 0);

    // Set the diagonal to be 2s
    for (unsigned int t = 0; t < T; t++)
    {
        C[t][t] = 2;
        B[t]++;
    }

    string line;
    // Skipping First Line
    getline(inputFile, line, '\n');
    while (getline(inputFile, line, '\n'))
    {
        stringstream ss(line);
        int date, team1, points1, team2, points2, winner, loser;

        ss >> date >> team1 >> points1 >> team2 >> points2;

        if (points1 > points2)
        {
            winner = team1 - 1;
            loser = team2 - 1;
        }
        else
        {
            winner = team2 - 1;
            loser = team1 - 1;
        }
        C[winner][loser]--;
        C[loser][winner]--;
        C[loser][loser]++;
        C[winner][winner]++;
        B[winner] += 0.5;
        B[loser] -= 0.5;
    }

    eliminacion_gaussiana(C, B);
    vector<double> r(T, 0);
    backward_substitution(C, r, B);
    return r;
}

void eliminacion_gaussiana(vector<vector<double>> &A, vector<double> &B)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            double m = A[j][i] / A[i][i];
            for (int k = i; k < A.size(); k++)
            {
                A[j][k] = A[j][k] - m * A[i][k];
            }
            B[j] = B[j] - m * B[i];
        }
    }
}
