#include<vector>
#include <fstream>
#include <iostream>
#include <sstream> // std::stringstream
#include "utils.h"
#include "math_utils.h"

vector<double> cmm(uint T, uint P, ifstream &inputFile);
void eliminacion_gaussiana(vector<vector<double>>& A, vector<double>& B);
