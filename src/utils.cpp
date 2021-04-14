using namespace std;

#include "utils.h"
#include <iomanip>
/**
 * Imprime en consola una matriz y un vector
 *
 * @param A matriz
 * @param b vector
 */
void print_matrix_vector (vector<vector<double > > &A, vector<double> &b) {
    for (uint i = 0; i < A.size(); i++){
        for(uint j = 0; j < A.size(); j++){
            printf("%f ", A[i][j]);
        }
        printf("| %f\n", b[i]);
    }
}

/**
 * Imprime en consola una matriz
 *
 * @param A matriz
 */
void print_matrix (vector<vector<double > > &A) {
    for (uint i = 0; i < A.size(); i++){
        for(uint j = 0; j < A.size(); j++){
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
}

/**
 * Imprime en consola un vector
 *
 * @param v vector
 */
void print_vector (vector<double> &v){
    for(uint i = 0; i < v.size(); i++){
        printf("%f\n", v[i]);
    }
}

/**
 * Escribe en un archivo de salida un vector.
 * Cada componente esta separada por un salto de linea.
 *
 * @param v Vector a imprimt
 * @param output Archivo de salida
 */
void write_vector (vector<double> &v, ofstream &output){
    for (uint i = 0; i < v.size(); i++){
        output << setprecision(14) << v[i] << "\n";
    }
}
