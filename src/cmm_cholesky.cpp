using namespace std;

#include "cmm_cholesky.h"

vector<double> cmm_cholesky(uint T, uint P, ifstream &inputFile)
{
    vector<vector<double>> C = vector<vector<double>>(T, vector<double>(T, 0));
    vector<double> B(T, 0);

    for (unsigned int t = 0; t < T; t++)
    {
        C[t][t] = 2;
        B[t]++;
    }

    string line;
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
    vector<vector<double>> L = cholesky(C);
    vector<vector<double>> LTras = trasponer(L);
    vector<double> y(T, 0);
    forward_substitution(L, y, B);
    vector<double> r(T, 0);
    backward_substitution(LTras, r, y);

    return r;
}

vector<vector<double>> cholesky(vector<vector<double>> &C) {
    int n = C.size();
    vector<vector<double>> L = vector<vector<double>>(C.size(), vector<double>(n, 0));

    for (uint i = 0; i < n; i++)
    {
        for (uint j = 0; j <= i; j++)
        {
            double sum = 0;
            if (j == i)
            {
                sum = kahan_sum_cuadrados(L[j]);
                L[j][j] = sqrt(C[j][j] - sum);
            }
            else
            {
                sum = kahan_sum_prod_interno(L[i], L[j]);
                L[i][j] = (C[i][j] - sum) / L[j][j];
            }
        }
    }

    return L;
}