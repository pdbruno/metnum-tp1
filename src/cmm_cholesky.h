#include <vector>
#include <fstream>
#include <iostream>
#include <sstream> // std::stringstream
#include "utils.h"
#include "math_utils.h"
#include <math.h>

vector<double> cmm_cholesky(uint T, uint P, ifstream &inputFile);
vector<vector<double>> cholesky(vector<vector<double>> &C);

