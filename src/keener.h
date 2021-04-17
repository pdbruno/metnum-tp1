#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include "math_utils.h"

vector<double> keener(uint T, uint P, ifstream &inputFile);

double h(double x, bool jugaron);
double signo(double num);
double g(const double Sij,const double Sji);
void power_iteration(vector<vector<double>> &A, vector<double> &rand_start, vector<double> &res, int cant_iter);
double norma(vector<double> &x);