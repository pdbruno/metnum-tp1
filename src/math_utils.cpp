using namespace std;

#include "math_utils.h"

void sort(vector<double>& r, vector<int>& indices)
{
  int i, keyIndices, j;
  double key;
  for (i = 1; i < r.size(); i++)
  {
    key = r[i];
    keyIndices = indices[i];
    j = i - 1;

    while (j >= 0 && r[j] > key)
    {
      r[j + 1] = r[j];
      indices[j + 1] = indices[j];
      j = j - 1;
    }
    r[j + 1] = key;
    indices[j + 1] = keyIndices;
  }
}

void backward_substitution(const vector<vector<double>> &A, vector<double> &x, const vector<double> &b)
{
    for (int i = A.size() - 1; i >= 0; i--)
    {
        double acc = kahan_sum_prod_interno(A[i], x);
        x[i] = (b[i] - acc) / A[i][i];
    }
}

void forward_substitution(const vector<vector<double>> &A, vector<double> &x, const vector<double> &b)
{
    int n = A.size();

	for(int i = 0; i < n; i++) {
        double acc = kahan_sum_prod_interno(A[i], x);
        x[i] = (b[i] - acc) / A[i][i];
	}
}

double kahan_sum_prod_interno(const vector<double> &A, vector<double> &x) // producto interno
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

double kahan_sum_cuadrados(const vector<double> &A) // suma cuadrados
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

vector<vector<double>> trasponer(vector<vector<double>> &A)
{
    vector<vector<double>> traspuesta = vector<vector<double>>(A.size(), vector<double>(A.size(), 0));
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A.size(); j++)
            traspuesta[i][j] = A[j][i];
    return traspuesta;
}

double suma_rec(const vector<double> &A, vector<double> &x, int start, int end)
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
        return suma_rec(A, x, start, mid) + suma_rec(A, x, mid, end);
    }
}

void producto_matricial(vector<vector<double>> &A, vector<double> &x, vector<double> &b)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            b[i] += A[i][j] * x[j];
        }
    }
}
