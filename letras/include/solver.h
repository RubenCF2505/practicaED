#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <string>
#include <utility>
#include <vector>
#include <algorithm>

#include "letters_set.h"
#include "dictionary.h"

using namespace std;

class Solver
{
private:
  Dictionary dictionary;
  LettersSet letters_set;

  int mejorPuntuacion;

public:
  /**
   * @brief metodo constructor por defecto
   *
   * Establece como mejor puntuacion -1
   */
  Solver() : mejorPuntuacion(-1) {};

  /**
   * @brief Metodo destructor de la clase solverW
   */
  ~Solver() {};

  /**
   * @brief Metodo constructor de la clase Solver
   *
   * @param dic objeto diccionario para comparar la palabra
   * @param lse objeto LetterSet
   *
   * Establece los atributos de la clase Solver con los parametros @param dic, @param lset y estableciendo mejorPuntuacion -1
   *
   */
  Solver(const Dictionary &dic, const LettersSet &lset) : dictionary(dic), letters_set(lset), mejorPuntuacion(-1) {};

  /**
   * @brief obtiene las soluciones con las letras disponibles
   * @param available_letters vector con las letras del juego
   * @param score_game validador para comprobar modo de juego
   *
   * Obtiene las soluciones posibles con las letras y las devuelve en un vector
   *
   * @return vector con las soluciones posibles
   */
  vector<string> getSolutions(const vector<char> &available_letters, bool score_game);

  /**
   * @brief obtiene la puntuacion del jugador en el tipo de partida por puntos
   *
   * @param available_letters vector con las letras del juego
   * @param palabra palabra a evaluar puntuacion
   *
   * @return numero de puntos de la palabra
   *
   */
  int valoraPuntos(const vector<char> &available_letters, const string &palabra);

  /**
   * @brief obtiene la puntuacion del jugador en el tipo de partida por longitud
   * @param available_letters vector con las letras del juego
   * @param palabra palabra a evaluar puntuacion
   *
   * @return numero de puntos de la palabra
   */
  int valoraTamanio(const vector<char> &available_letters, const string &palabra);


  /**
   * @brief metodo de lectura del atributo mejorPuntuacion
   * 
   * @return mejorPuntuacion
   */
  int getMejorPuntuacion() const { return mejorPuntuacion; }

};

#endif // __SOLVER_H__
