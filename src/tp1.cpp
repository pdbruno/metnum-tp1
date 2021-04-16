using namespace std;
#include "tp1.h"


int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Formato de parametros invalido.\n");
    return 1;
  }
  // parametros por linea de comando
  uint mode = atoi(argv[3]);
  char *input = argv[1];
  char *output = argv[2];

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
  vector<int> indices(T, 0);




  switch (mode) {
  case 0:
    r = cmm(T, P, inputFile);
    break;
  case 1:
    r = wp(T, P, inputFile);
    break;
  case 2:
    r = keener(T, P, inputFile);
    break;
  }

  inputFile.close();

  ofstream outputFile;
  outputFile.open(output);

  //write_vector(r, outputFile);
  print_vector(r);

  for (int i = 0; i < T; i++) {
    indices[i] = i;
  }

  int i, keyIndices, j;
  double key;
  for (i = 1; i < T; i++) {
    key = r[i];
    keyIndices = indices[i];
    j = i - 1;

    while (j >= 0 && r[j] > key) {
      r[j + 1] = r[j];
      indices[j + 1] = indices[j];
      j = j - 1;
    }
    r[j + 1] = key;
    indices[j + 1] = keyIndices;
  }

  write_vector(r, indices, outputFile);


  outputFile.close();
  return 0;
}
