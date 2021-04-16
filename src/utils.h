#include <iostream>
#include <fstream>
#include <vector>
#include <map>
/**
 * Imprime en consola una matriz y un vector
 *
 * @param A matriz
 * @param b vector
 */
void print_matrix_vector (vector<vector<double > > &A, vector<double> &b);
/** 
 * Imprime en consola una matriz
 *
 * @param A matriz
 */
void print_matrix (vector<vector<double > > &A);
/**
 * Imprime en consola un vector
 *
 * @param v vector
 */
void print_vector (vector<double> &v);
void print_vector (vector<int> &v);

/**
 * Escribe en un archivo de salida un vector.
 * Cada componente esta separada por un salto de linea.
 *
 * @param v Vector a imprimt
 * @param output Archivo de salida
 */
void write_vector (vector<double> &v, vector<int> &indices, ofstream &output);
