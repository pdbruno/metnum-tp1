using namespace std;

#include "keener.h"

/*
RECORDAR CITAS (EN DESARROLLO)>
https://es.wikipedia.org/wiki/M%C3%A9todo_de_las_potencias

Paper 151-2008
Generalizing Google’s PageRank to Rank National Football League Teams

*/
vector<double> keener(uint T, uint P, ifstream &inputFile){
    vector<vector<double>> K(T, vector<double>(T,0)); //keener matrix
    vector<vector<double>> S(T, vector<double>(T,0)); // matriz de puntos anotados por i contra j
    vector<vector<bool>> J(T, vector<bool>(T, false)); // Jij=true si i y j jugaron


    string line;
    // Skipping First Line
    getline(inputFile, line, '\n');     
    while (getline(inputFile, line,'\n')) {
        stringstream ss(line);
        int date, team1, points1, team2, points2, winner, loser, wpoints, lpoints;
        ss >> date >> team1 >> points1 >> team2 >> points2;

        if (points1 > points2) {
            winner = team1-1;
            loser = team2-1;

            wpoints = points1;
            lpoints = points2;
        }
        else {
            winner = team2-1;
            loser = team1-1;

            wpoints = points2;
            lpoints = points1;
        }
        

        J[winner][loser] = true;
        J[loser][winner] = true;

        S[winner][loser] += max(wpoints, lpoints);
        S[loser][winner] += min(wpoints, lpoints);;
        // recordar que los Sij y los Sji son la suma de los goles a lo largo de los partidos

    }
    for(int i = 0 ; i < T ; i++){
        for(int j = 0 ; j< T ; j++){
            K[i][j] = h(   g(   S[i][j], S[j][i]   ), J[i][j]   );
        }
    }

    vector<double> res(T, 0);
    vector<double> rand_start(T, 1); // Un vector arbitrario
    power_iteration(K, rand_start, res, 1000);
    return res;

}

double h(double x, bool jugaron){
    // Keener’s smoothing function: Calcula la variable de entrada en la funcion h para encontrar Kij. 
    // El efecto del puntaje en el ranking es cada vez menor al aumentar
    double res;
    if(jugaron)
        res = 0.5 + 0.5 *signo(x - 0.5)* sqrt(abs((2 * x) -1)     );
    else
        res = 0;    
    return res;
}

double signo(double num){
    if(num>0)
        return 1;
    else if(num<0)
        return -1;
    else
        return 0;
}

double g(const double Sij,const double Sji){
    double numerador = Sij + 1;
    double denominador = Sij + Sji + 2;
    return numerador/denominador;
}

void power_iteration(vector<vector<double>> &A, vector<double> &rand_start, vector<double> &res, int cant_iter)
{
    vector<double> b_i = rand_start;

    for (int i = 0; i < cant_iter; i++) {
        producto_matricial(A, b_i, res);
        double norm = norma(res);
        for(int k = 0; k< res.size(); k++){
            res[k] = res[k] / norm;
            b_i[k] = res[k];
        }
    }
}

double norma(vector<double> &x) {
    double norm = 0;
    for (int j = 0; j < x.size(); j++) {
        norm += x[j] * x[j];   
    }
    return sqrt(norm);
}