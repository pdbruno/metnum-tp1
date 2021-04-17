using namespace std;

#include "cmm_cholesky.h"

vector<double> cmm_cholesky(uint T, uint P, ifstream &inputFile)
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
    vector<vector<double>> L = lDeCholesky(C);
    vector<vector<double>> LTras = trasponer(L);
    //eliminacion_gaussiana(C, B);
    vector<double> y(T, 0);
    forward_substitution(L, y, B);
    vector<double> r(T, 0);
    backward_substitution_cholesky(LTras, r, y);

    return r;
}

vector<vector<double>> trasponer(vector<vector<double>> &A)
{
    vector<vector<double>> traspuesta = vector<vector<double>>(A.size(), vector<double>(A.size(), 0));
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A.size(); j++)
            traspuesta[i][j] = A[j][i];
    return traspuesta;
}

void backward_substitution_cholesky(const vector<vector<double>> &A, vector<double> &x, const vector<double> &b)
{
    for (int i = A.size() - 1; i >= 0; i--)
    {
        double acc = kahanSumProdInterno(A[i], x);
        x[i] = (b[i] - acc) / A[i][i];
    }
}

void forward_substitution(const vector<vector<double>> &A, vector<double> &x, const vector<double> &b)
{
    int n = A.size();

	for(int i = 0; i < n; i++) {
        double acc = kahanSumProdInterno(A[i], x);
        x[i] = (b[i] - acc) / A[i][i];
	}
}

double kahanSumProdInterno(const vector<double> &A, vector<double> &x) //producto interno
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

double kahanSumCuadrados(const vector<double> &A) //suma cuadrados
{
    double sum = 0.0;
    double c = 0.0;

    for (int i = 0; i < A.size(); i++)
    {
        double y = (A[i] * A[i]) - c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}

vector<vector<double>> lDeCholesky(vector<vector<double>> &C) {
    int n = C.size();
    vector<vector<double>> L = vector<vector<double>>(C.size(), vector<double>(n, 0));

    for (uint i = 0; i < n; i++)
    {
        for (uint j = 0; j <= i; j++)
        {
            double sum = 0;
            if (j == i)
            {
                sum = kahanSumCuadrados(L[j]);
                L[j][j] = sqrt(C[j][j] - sum);
            }
            else
            {
                sum = kahanSumProdInterno(L[i], L[j]);
                L[i][j] = (C[i][j] - sum) / L[j][j];
            }
        }
    }

    return L;
}