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
  vector<double> indices(T, 0);

  for (int i = 0; i < T; i++) {
    indices[i] = i;
  }


  switch (mode) {
  case 0:
    r = cmm(T, P, inputFile);
    break;
  case 1:
    r = wp(T, P, inputFile);
  case 2:
    r = keener(T, P, inputFile);
    break;
  }

  inputFile.close();

  ofstream outputFile;
  outputFile.open(output);

  write_vector(r, outputFile);
  print_vector(r);

  int i, key, keyIndices, j;
  for (i = 1; i < T; i++) {
    key = r[i];
    keyIndices = r[i];
    j = i - 1;

    /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && r[j] > key) {
      r[j + 1] = r[j];
      r[j + 1] = indices[j];
      j = j - 1;
    }
    indices[j + 1] = key;
  }


  outputFile.close();
  return 0;
}
