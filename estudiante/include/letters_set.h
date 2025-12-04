#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <iostream>
#include <map>

using namespace std;

struct LetterInfo
{
  unsigned int repetitions;
  unsigned int score;

  /**
   * @brief Constructor por defecto
   */
  LetterInfo(): repetitions(0), score(0){}

  /**
   * @brief Constructor con parámetros
   *
   * @param reps Número de repeticiones del carácter en la partida
   * @param score Puntuación del carácter
   */
  LetterInfo(unsigned int reps, unsigned int score): repetitions(reps), score(score){};
};


class LettersSet
{
private:
  map<char, LetterInfo> charSet;

public:
  LettersSet(){};
  ~LettersSet(){};

  int size() const;
  bool empty() const;
  void clear();

  void insert(char c, int rep, int score);
  void erase(char c);
  LetterInfo& operator[](char c);
  LetterInfo operator[](char c) const;

  // Iteradores --------------------------------------------------------
  class iterator
  {
  private:
    map<char, LetterInfo>::iterator it;

  public:
    iterator() = default;
    iterator(const iterator &other) : it(other.it) {}
    iterator(const map<char, LetterInfo>::iterator &other) : it(other) {}

    pair<const char, LetterInfo> &operator*() { return *it; }
    const pair<const char, LetterInfo> &operator*() const { return *it; }

    iterator &operator++() { ++it; return *this; }

    bool operator==(const iterator &other) const { return it == other.it; }
    bool operator!=(const iterator &other) const { return it != other.it; }
    
    friend class LettersSet;
  };

  class const_iterator
  {
  private:
    map<char, LetterInfo>::const_iterator it;

  public:
    const_iterator() = default;
    const_iterator(const map<char, LetterInfo>::const_iterator &other) : it(other) {}
    const_iterator(const const_iterator &other) : it(other.it) {}

    const pair<const char, LetterInfo> &operator*() const { return *it; }

    const_iterator &operator++() { ++it; return *this; }

    bool operator==(const const_iterator &other) const { return it == other.it; }
    bool operator!=(const const_iterator &other) const { return it != other.it; }
    
    friend class LettersSet;
  };

  iterator find(char c);
  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  int getScore(const string &palabra) const;
  int getOcurrences(char c);
  int getTotalLetters();
  void loadFromFile(string filename);

  friend istream &operator>>(istream &is, LettersSet &ltr);
  friend ostream &operator<<(ostream &os, LettersSet &ltr);
};

#endif
