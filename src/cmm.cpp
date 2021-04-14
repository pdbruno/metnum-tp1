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

void backward_substitution(const vector<vector<double>> &A, vector<double> &x, const vector<double> &b)
{
    for (int i = A.size() - 1; i >= 0; i--)
    {
        double acc = kahanSum(A[i], x);
        /* double acc = 0;
        for (int j = i + 1; j < A.size(); j++)
        {
            acc += A[i][j] * x[j];
        } */
        x[i] = (b[i] - acc) / A[i][i];
    }
}

double sumaLoca(const vector<double> &A, vector<double> &x, int start, int end)
{
    if (start == end - 1)
    {
        return A[start] * x[start];
    }
    else if (start >= end)
    {
        return 0;
    }
    else
    {
        int mid = (end + start) / 2;
        return sumaLoca(A, x, start, mid) + sumaLoca(A, x, mid, end);
    }
}

void producto_matricial(vector<vector<double>> &A, vector<double> &x, vector<double> &b)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            b[i] = A[i][j] * x[j];
        }
    }
}

double kahanSum(const vector<double> &A, vector<double> &x)
{
    double sum = 0.0;
    double c = 0.0;

    for (int i = 0; i < A.size(); i++)
    {
        double y = (A[i] * x[i]) - c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}
