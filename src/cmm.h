#include<vector>
#include <fstream>
#include <iostream>
#include <sstream> // std::stringstream
#include "utils.h"

vector<double> cmm(uint T, uint P, ifstream &inputFile);
void eliminacion_gaussiana(vector<vector<double>>& A, vector<double>& B);
void backward_substition(vector<vector<double>>& A, vector<double>& x, vector<double>& b);
void producto_matricial(vector<vector<double>>& A, vector<double>& x, vector<double>& b);