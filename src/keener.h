#include<vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include "utils.h"

vector<double> keener(uint T, uint P, ifstream &inputFile);

double h(double x, bool jugaron);
double signo(double num);
double g(const double Sij,const double Sji);
void power_iteration(vector<vector<double>> &A, vector<double> &rand_start, vector<double> &res, int cant_iter);
void producto_matricial_keener(vector<vector<double>> &A, vector<double> &x, vector<double> &b); // TODO FIX
double norma(vector<double> &x);