#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "dictionary.h"
#include "letters_bag.h"
#include "letters_set.h"
#include "solver.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 5){
    cout << "Los parametros son: " << endl;
    cout << "1.- El fichero con el diccionario" << endl;
    cout << "2.- El fichero con las letras" << endl;
    cout << "3.- Número de letras con que jugar"<< endl;
    cout << "4.- Tipo de partida (L: Longitud, P: Puntos)"<< endl;
    return 1;
  }

  ifstream f_dic(argv[1]);
  ifstream f_letters(argv[2]);
  int num_letters = stoi(argv[3]);
  char tipo_partida = argv[4][0];

  bool score_game;
  switch(tipo_partida)
  {
    case 'L':
    case 'l':
      score_game = false;
      break;
    case 'P':
    case 'p':
      score_game = true;
      break;
    default:
      cout << "Tipo de partida no valido. Use L o P." << endl;
      return 2;
  }

  Dictionary dic;
  LettersSet lset;

  f_dic >> dic;
  f_letters >> lset;

  LettersBag lbag(lset);
  Solver solver(dic, lset);

  string respuesta = "S";

  do
  {
    vector<char> available_letters = lbag.extractLetter(num_letters);

    // Comienza Información de Partida

    cout << endl << "Modo de juego: ";
    if(score_game)
      cout << "Partida por PUNTOS" << endl;
    else
      cout << "Partida por LONGITUD" << endl;

    cout << endl << "Letras disponibles: " << endl;
    for(char c : available_letters)
      cout << c << " ";
    cout << endl << endl;

    // Jugador Introduce su Palabra
    string palabra;

    cout << "Introduzca su palabra: ";
    cin >> palabra;
    for(char &c : palabra)
      c = tolower(c);

    int puntos = -1;
    if (score_game) puntos = solver.valoraPuntos(available_letters, palabra);
    else puntos = solver.valoraTamanio(available_letters, palabra);

    if (puntos != -1)
      cout << palabra  << " Puntuación: " << puntos << endl;
    else
      cout << "La palabra no se puede formar con las letras disponibles." << endl;

    // Obtener Mejores Soluciones
    vector<string> soluciones = solver.getSolutions(available_letters, score_game);
    cout << endl << "Mis soluciones son: " << endl;

    puntos = solver.getMejorPuntuacion();
    for(string s : soluciones)
      cout << s << " Puntuación: " << puntos << endl;

    cout << endl << "¿Quieres seguir jugando[S/N]? " << endl;
    cin >> respuesta;
  } while (respuesta == "S" || respuesta == "s");
  
  return 0;

}
