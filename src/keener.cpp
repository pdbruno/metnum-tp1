#include "keener.h"

vector<double> keener(uint T, uint P, ifstream &inputFile){
    vector<vector<double>> K(T, vector<double>(T,0)); //keener matrix
    vector<double> rd(T,0);// vector r derecho
    vector<double> rank(T,0);// vector r izquierdo
    vector<vector<double>> S(T, vector<double>(T,0)); // matriz de puntos anotados por i contra j
    vector<vector<bool>> J(T, vector<bool>(T, false)); // Jij=true si i y j jugaron


    string line;
    // Skipping First Line
    getline(inputFile, line, '\n');     
    while (getline(inputFile, line,'\n')) {
        stringstream ss(line);
        int date, winner, wpoints, loser, lpoints;

        char c;

        ss >> date >> winner >> wpoints >> loser >> lpoints;
        loser--;
        winner--;
        
        J[winner][loser] = true;
        J[loser][winner] = true;

        S[winner][loser] += wpoints;
        S[loser][winner] += lpoints;
        // recordar que los Sij y los Sji son la suma de los goles a lo largo de los partidos

    }

    for(int i = 0 ; i < T ; i++){
        for(int j = 0 ; j< T ; j++){
            K[i][j] = h(   g(   S[i][j], S[j][i]   ), J[i][j]   );
        }
    }

    //falta: encontrar lambda -> encontrar rd -> resolver K*rank = lambda*rd
    
    return rank;

}

double h(double x, bool jugaron){
    // Keener’s smoothing function: Calcula la variable de entrada en la funcion h para encontrar Kij. 
    // El efecto del puntaje en el ranking es cada vez menor al aumentar
    double res;
    if(jugaron)
        res = 0.5 + 0.5 * sqrt(abs(2 * x -1) * signo(x - 0.5));
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
    // Keener’s smoothing function: Calcula la variable de entrada en la funcion h para encontrar Kij. 
    // El efecto del puntaje en el ranking es cada vez menor al aumentar
    double numerador = Sij + 1;
    double denominador = Sij + Sji + 2;
    return numerador/denominador;
}