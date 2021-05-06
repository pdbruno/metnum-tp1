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
  ifstream input_file;
  input_file.open(input);

  if (!input_file.is_open())
  {
    printf("Archivo de entrada invalido.\n");
    return 1;
  }

  // T: cantidad de equipos
  // P: cantidad de partidos
  uint T, P;
  input_file >> T >> P;

  vector<double> r; // ranking
  vector<int> indices(T, 0);

  switch (mode)
  {
  case 0:
    r = cmm(T, P, input_file);
    break;
  case 1:
    r = wp(T, P, input_file);
    break;
  case 2:
    r = keener(T, P, input_file);
    break;
  case 3:
    r = cmm_cholesky(T, P, input_file);
    break;
  case 4:
    ranking_compare(T, P, input, output);
    input_file.close();
    return 0;
  }

  input_file.close();
  ofstream output_file;
  output_file.open(output);

  print_vector(r);
  write_vector(r, output_file);

  output_file.close();
  return 0;
}

void ranking_compare(uint T, uint P, char *input, char *output)
{
    vector<double> r_cmm;       // ranking
    vector<double> r_cmm_2;       // ranking
    vector<int> indices_cmm(T, 0);    // ranking
    vector<double> r_wp;        // ranking
    vector<int> indices_wp(T, 0);     // ranking
    vector<double> r_keener;    // ranking
    vector<int> indices_keener(T, 0); // ranking
    for (int i = 0; i < T; i++)
    {
      indices_cmm[i] = i;
      indices_wp[i] = i;
      indices_keener[i] = i;
    }

    ifstream input_file;
    ifstream input_file2;
    ifstream input_file3;

    input_file.open(input);
    r_cmm = cmm(T, P, input_file);
    input_file.close();

    input_file2.open(input);
    r_wp = wp(T, P, input_file2);
        input_file2.close();
    input_file2.open(input);

    r_cmm_2 = wp(T, P, input_file2);
    input_file2.close();

    input_file3.open(input);
    r_keener = keener(T, P, input_file3);
    input_file3.close();

    sort(r_cmm, indices_cmm);
    sort(r_wp, indices_wp);
    sort(r_keener, indices_keener);

    vector<int> diferencias_cmm(T, 0); // ranking
    vector<int> diferencias_wp(T, 0); // ranking
    vector<int> diferencias_keener(T, 0); // ranking

    for (int i = 0; i < T; i++) {
      diferencias_wp[indices_wp[i]] = i;
      diferencias_keener[indices_keener[i]] = i;
    }

    vector<double> diferencia(T, 0); // ranking
    for (int i = 0; i < T; i++) {
      diferencia[i] = (double)diferencias_wp[i] - diferencias_keener[i];
      if (diferencia[i] < 0) {
        diferencia[i] = -1 * diferencia[i];
      }
    }
    sort(r_cmm_2, diferencia);



    ofstream output_file;
    output_file.open(output);
    write_vector(diferencia, output_file);
    output_file << "CON CMM" << '\n';
    write_vector(r_cmm, indices_cmm, output_file);
    output_file << "CON WP" << '\n';
    write_vector(r_wp, indices_wp, output_file);
    output_file << "CON KEENER" << '\n';
    write_vector(r_keener, indices_keener, output_file);

    output_file.close();
}