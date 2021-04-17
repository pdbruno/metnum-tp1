using namespace std;
#include "tp1.h"

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("Formato de parametros invalido.\n");
    return 1;
  }
  // parametros por linea de comando
  uint mode = atoi(argv[3]);
  char *input = argv[1];
  char *output = argv[2];

  // lectura del input
  ifstream inputFile;
  inputFile.open(input);

  if (!inputFile.is_open())
  {
    printf("Archivo de entrada invalido.\n");
    return 1;
  }

  // T: cantidad de equipos
  // P: cantidad de partidos
  uint T, P;
  inputFile >> T >> P;

  vector<double> r; // ranking
  vector<int> indices(T, 0);

  switch (mode)
  {
  case 0:
    r = cmm(T, P, inputFile);
    break;
  case 1:
    r = wp(T, P, inputFile);
    break;
  case 2:
    r = keener(T, P, inputFile);
    break;
  case 3:
    vector<double> rCMM;       // ranking
    vector<int> indicesCMM(T, 0);    // ranking
    vector<double> rWP;        // ranking
    vector<int> indicesWP(T, 0);     // ranking
    vector<double> rKEENER;    // ranking
    vector<int> indicesKEENER(T, 0); // ranking
    for (int i = 0; i < T; i++)
    {
      indicesCMM[i] = i;
      indicesWP[i] = i;
      indicesKEENER[i] = i;
    }

    ifstream inputFile2;
    ifstream inputFile3;

    rCMM = cmm(T, P, inputFile);
    inputFile.close();

    inputFile2.open(input);
    rWP = wp(T, P, inputFile2);
    inputFile2.close();

    inputFile3.open(input);
    rKEENER = keener(T, P, inputFile3);
    inputFile3.close();

    sort(rCMM, indicesCMM);
    sort(rWP, indicesWP);
    sort(rKEENER, indicesKEENER);

    ofstream outputFile;
    outputFile.open(output);
    outputFile << "CON CMM" << '\n';
    write_vector(rCMM, indicesCMM, outputFile);
    outputFile << "CON WP" << '\n';
    write_vector(rWP, indicesWP, outputFile);

    outputFile << "CON KEENER" << '\n';
    write_vector(rKEENER, indicesKEENER, outputFile);

    outputFile.close();
    
    return 0;
  }


  ofstream outputFile;
  outputFile.open(output);

  print_vector(r);
  //write_vector(r, outputFile);
  write_vector(r, indices, outputFile);

  outputFile.close();
  return 0;
}


void sort(vector<double>& r, vector<int>& indices)
{
  int i, keyIndices, j;
  double key;
  for (i = 1; i < r.size(); i++)
  {
    key = r[i];
    keyIndices = indices[i];
    j = i - 1;

    while (j >= 0 && r[j] > key)
    {
      r[j + 1] = r[j];
      indices[j + 1] = indices[j];
      j = j - 1;
    }
    r[j + 1] = key;
    indices[j + 1] = keyIndices;
  }
}
