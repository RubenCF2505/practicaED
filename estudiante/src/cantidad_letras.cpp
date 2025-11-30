#include <fstream>
#include <iostream>
#include <cmath>
#include "dictionary.h"
#include "letters_set.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 4){
    cout << "Los parametros son: " << endl;
    cout << "1.- El fichero con el diccionario" << endl;
    cout << "2.- El fichero con las letras" << endl;
    cout << "3.- El fichero de salida"<<endl;
    return 0;
  }
  
  ifstream f_dic(argv[1]);
  ifstream f_letters(argv[2]);
  ofstream f_out(argv[3]);

  Dictionary dic;
  LettersSet lset;

  f_dic >> dic;
  f_letters >> lset;

  int total_letters = dic.getTotalLetters();

  cout << lset << endl << endl;

  cout << total_letters << endl << endl;

  f_out << "Letra\tOcurrencias\tFrecuencia\tPuntuacion\n";
  for (LettersSet::iterator it = lset.begin(); it != lset.end(); ++it)
  {
    char c = (*it).first;
    LetterInfo info = (*it).second;

    int occ = dic.getOccurrences(c);
    double freq = (double)occ / total_letters;
    double puntuacion_media = info.score * freq;

    f_out << c << "\t" << occ << "\t" << freq << "\t" << puntuacion_media << "\n";
  }

  return 0;
}
