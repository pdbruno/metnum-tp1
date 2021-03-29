using namespace std;
#include "tp1.h"


int main (int argc, char *argv[]) {
 if (argc != 4) {
    printf("Formato de parametros invalido.\n");
    return 1;
  }
    // parametros por linea de comando
  uint mode = atoi(argv[1]);
  char *input = argv[2];
  char *output = argv[3];

  if (mode > 2) {
    printf("Metodo invalido");
    return 1;
  }

  // lectura del input
  ifstream inputFile;
  inputFile.open(input);

  if (!inputFile.is_open()) {
    printf("Archivo de entrada invalido.\n");
    return 1;
  }

  // T: cantidad de equipos
  // P: cantidad de partidos
  uint T, P;
  inputFile >> T >> P;

  vector<double> r; // ranking

  switch (mode) {
    case 0:
      r = cmm();
      break;
    case 1:
      r = wp();
      break;
  }

  inputFile.close();

  ofstream outputFile;
  outputFile.open(output);

  write_vector(r, outputFile);
  print_vector(r);

  outputFile.close();
  return 0;
}
