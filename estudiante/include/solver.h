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
  Solver() : mejorPuntuacion(-1) {};
  ~Solver() {};
  Solver(const Dictionary& dic, const LettersSet& lset) : dictionary(dic), letters_set(lset), mejorPuntuacion(-1) {};
  vector<string> getSolutions(const vector<char>& available_letters, bool score_game);
  int valoraPuntos(const vector<char>& available_letters, const string& palabra);
  int valoraTamanio(const vector<char>& available_letters, const string& palabra);

  int getMejorPuntuacion() const { return mejorPuntuacion; }
};

#endif // __SOLVER_H__
