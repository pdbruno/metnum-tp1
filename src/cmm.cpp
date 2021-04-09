using namespace std;

#include "cmm.h"

vector<double> cmm(uint T, uint P, ifstream &inputFile) {
    // Initialize the matrix as a n x n array of 0.
    vector<vector<double>> C = vector<vector<double> >(T, vector<double>(T,0));
    vector<vector<double>> C2 = vector<vector<double> >(T, vector<double>(T,0));
    vector<double> B(T, 0);
    vector<double> B2(T, 0);

    // Set the diagonal to be 2s
    for(unsigned int t = 0; t < T; t++) {
        C[t][t] = 2;
        C2[t][t] = 2;
    }

    string line;
    // Skipping First Line
    getline(inputFile, line, '\n');     
    while (getline(inputFile, line,'\n')) {
        stringstream ss(line);
        double date, winner, wpoints, loser, lpoints;

        char c;

        ss >> date >> winner >> wpoints >> loser >> lpoints;
        loser--;
        winner--;
        C2[winner][loser] = C[winner][loser] = C[winner][loser] - 1;
        C2[loser][winner] = C[loser][winner] = C[loser][winner] - 1;
        C2[loser][loser] = C[loser][loser] = C[loser][loser] + 1;
        C2[winner][winner] = C[winner][winner] = C[winner][winner] + 1;
        B2[winner] = B[winner] = B[winner] + 0.5;
        B2[loser] = B[loser] = B[loser] - 0.5;
    }

    for (int i = 0; i < B.size(); i++)
    {
        B[i]++;
        B2[i]++;
    }
    
    cout<<"La matriz C es: \n";
    print_matrix(C);
    cout<<"El vector b es: \n";
    print_vector(B);
    
    vector<double> r(T, 0);
    eliminacion_gaussiana(C, B);
    backward_substition(C, r, B);
    vector<double> KK(T, 0);
    producto_matricial(C2, r, KK);
    cout << "===== Ranking =====" << '\n';
    print_vector(r);
    cout << "===== KK =====" << '\n';
    print_vector(KK);
    cout << "===== B2 =====" << '\n';
    print_vector(B2);
    return r;
}

void eliminacion_gaussiana(vector<vector<double>>& A, vector<double>& B){
    
    /*for(int i = 1; i < A.size(); i++){
        step(i, A);
    }*/
    // --version modularizada de EG--
    
    for (int i = 0; i < A.size(); i++) {
        for(int j = i + 1; j < A.size(); j++) {
            double m = A[j][i] / A[i][i];
            for(int k = i; k < A.size(); k++) {
                A[j][k] = A[j][k] - m * A[i][k];
            }
            B[j] = B[j] - m * B[i];
        }
    }
}

void backward_substition(vector<vector<double>>& A, vector<double>& x, vector<double>& b){    
    for(int i = A.size() - 1; i >= 0; i--){
        double acc = 0;
        for(int j = i+1; j < A.size(); j++) {
            acc += A[i][j] * x[j];
        }
        x[i] = (b[i] - acc) / A[i][i];
    }
}

void producto_matricial(vector<vector<double>>& A, vector<double>& x, vector<double>& b){
    for (int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A.size(); j++) {
            b[i] = A[i][j] * x[j];
        }
    }
}

/*
void step(short paso, vector<vector<double>>& mat){
    vector<double> row_i = mat[paso-1];
    double m_Denom = row_i[paso-1];

    for(int i = paso + 1; i< mat.size() ; i++){
        mat[i] = subRows(mat[i], row_i, mat[i][paso]/m_Denom);
    }



}

vector<double> multRow(double cohef, vector<double> row){
    for(int i = 0 ; i < row.size(); i++){
        row[i] = row[i]*cohef;
    }
    return row;
}
vector<double> subRows(vector<double> row_l, vector<double> row_r, double cohef_r){
    // row_l = row_l- cohef_r * row_r
    for(int i = 0 ; i < row_l.size() ; i++){
        row_l[i] -= cohef_r * row_r[i];
    }
    return row_l;
}
*/