#include <vector>
#include <fstream>
#include <iostream>
#include <sstream> // std::stringstream
#include "utils.h"
#include <math.h>

vector<double> cmm_cholesky(uint T, uint P, ifstream &inputFile);
void backward_substitution_cholesky(const vector<vector<double>>& A, vector<double>& x,const vector<double>& b);

void producto_matricial(vector<vector<double>>& A, vector<double>& x, vector<double>& b);
void test_BS();

void step(short paso, vector<vector<double>>& mat);
vector<double> multRow(double cohef, vector<double> row);
vector<double> subRows(vector<double> row_l, vector<double> row_r, double cohef_r);
double sumaLoca(const vector<double> &A, vector<double> &x,  int start, int end);
double kahanSumProdInterno(const vector<double> &A, vector<double> &x);
double kahanSumCuadrados(const vector<double> &A);
vector<vector<double>> lDeCholesky(vector<vector<double>> &C);
vector<vector<double>> trasponer(vector<vector<double>> &A);
void forward_substitution(const vector<vector<double>> &A, vector<double> &x, const vector<double> &b);
