#include<vector>
#include <fstream>
#include <iostream>
#include <sstream> // std::stringstream
#include "utils.h"

vector<double> cmm(uint T, uint P, ifstream &inputFile);
void eliminacion_gaussiana(vector<vector<double>>& A, vector<double>& B);
void backward_substitution(const vector<vector<double>>& A, vector<double>& x,const vector<double>& b);
void backward_substitution_2(const vector<vector<double>>& A, vector<double>& x,const vector<double>& b);

void producto_matricial(vector<vector<double>>& A, vector<double>& x, vector<double>& b);
void test_BS();

void step(short paso, vector<vector<double>>& mat);
vector<double> multRow(double cohef, vector<double> row);
vector<double> subRows(vector<double> row_l, vector<double> row_r, double cohef_r);
double sumaLoca(const vector<double> &A, vector<double> &x,  int start, int end);
double kahanSum(const vector<double> &A, vector<double> &x);