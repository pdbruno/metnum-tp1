#include<vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

vector<double> keener(uint T, uint P, ifstream &inputFile);

double h(double x, bool jugaron);
double signo(double num);
double g(const double Sij,const double Sji);