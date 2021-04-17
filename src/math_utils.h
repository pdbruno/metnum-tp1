#include <sstream>
#include "utils.h"
#include <math.h>

vector<vector<double>> trasponer(vector<vector<double>> &A);
void forward_substitution(const vector<vector<double>> &A, vector<double> &x, const vector<double> &b);
double kahan_sum_prod_interno(const vector<double> &A, vector<double> &x);
double kahan_sum_cuadrados(const vector<double> &A);
void backward_substitution(const vector<vector<double>>& A, vector<double>& x,const vector<double>& b);
void sort(vector<double>& r, vector<int>& indices);
void producto_matricial(vector<vector<double>>& A, vector<double>& x, vector<double>& b);
double suma_rec(const vector<double> &A, vector<double> &x,  int start, int end);
