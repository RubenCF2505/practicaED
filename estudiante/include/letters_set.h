#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <iostream>
#include <map>

using namespace std;

/**
 * @struct LetterInfo
 * @brief Estructura que almacena la información asociada a una letra.
 *
 * Contiene el número de repeticiones de la letra en la partida y la puntuación
 * que aporta cada aparición de dicha letra.
 */
struct LetterInfo
{
  unsigned int repetitions;
  unsigned int score;

  /**
   * @brief Constructor por defecto
   */
  LetterInfo() : repetitions(0), score(0) {}

  /**
   * @brief Constructor con parámetros
   *
   * @param reps Número de repeticiones del carácter en la partida
   * @param score Puntuación del carácter
   */
  LetterInfo(unsigned int reps, unsigned int score) : repetitions(reps), score(score) {};
};

/**
 * @class LettersSet
 * @brief Clase que representa un conjunto de letras con su información asociada.
 *
 * Internamente se implementa mediante un `map<char, LetterInfo>` que asocia
 * cada carácter con sus repeticiones y puntuación.
 */
class LettersSet
{
private:
  map<char, LetterInfo> charSet;

public:
  /**
   * @brief Constructor por defecto.
   */
  LettersSet() {};

  /**
   * @brief Destructor.
   */
  ~LettersSet() {};

  /**
   * @brief Devuelve el número de letras almacenadas en el conjunto.
   * @return Número de elementos en el conjunto.
   */
  int size() const;

  /**
   * @brief Comprueba si el conjunto está vacío.
   * @return true si no contiene letras, false en caso contrario.
   */
  bool empty() const;

  /**
   * @brief Elimina todas las letras del conjunto.
   */
  void clear();

  /**
   * @brief Inserta una nueva letra en el conjunto.
   * @param c Carácter a insertar.
   * @param rep Número de repeticiones de la letra.
   * @param score Puntuación asociada a la letra.
   */
  void insert(char c, int rep, int score);

  /**
   * @brief Elimina una letra del conjunto.
   * @param c Carácter a eliminar.
   */
  void erase(char c);

  /**
   * @brief Accede a la información de una letra.
   * @param c Carácter a consultar.
   * @return Referencia a la información de la letra.
   */
  LetterInfo &operator[](char c);
  /**
   * @brief Accede a la información de una letra (modo constante).
   * @param c Carácter a consultar.
   * @return Información de la letra.
   */
  LetterInfo operator[](char c) const;

  // ------ Iteradores -------------------------------------------------------
  /**
   * @class LettersSet::iterator
   * @brief Iterador no constante para recorrer el conjunto de letras.
   */
  class iterator
  {
  private:
    map<char, LetterInfo>::iterator it;

  public:
    iterator() = default;
    iterator(const iterator &other) : it(other.it) {}
    iterator(const map<char, LetterInfo>::iterator &other) : it(other) {}

    /**
     * @brief Operador de desreferencia.
     * @return Referencia al par (carácter, información).
     */
    pair<const char, LetterInfo> &operator*() { return *it; }
    const pair<const char, LetterInfo> &operator*() const { return *it; }

    /**
     * @brief Avanza el iterador.
     * @return Referencia al propio iterador incrementado.
     */
    iterator &operator++()
    {
      ++it;
      return *this;
    }

    bool operator==(const iterator &other) const { return it == other.it; }
    bool operator!=(const iterator &other) const { return it != other.it; }

    friend class LettersSet;
  };

  /**
   * @class LettersSet::const_iterator
   * @brief Iterador constante para recorrer el conjunto de letras.
   */
  class const_iterator
  {
  private:
    map<char, LetterInfo>::const_iterator it;

  public:
    const_iterator() = default;
    const_iterator(const map<char, LetterInfo>::const_iterator &other) : it(other) {}
    const_iterator(const const_iterator &other) : it(other.it) {}

    /**
     * @brief Operador de desreferencia.
     * @return Referencia constante al par (carácter, información).
     */
    const pair<const char, LetterInfo> &operator*() const { return *it; }

    /**
     * @brief Avanza el iterador.
     * @return Referencia al propio iterador incrementado.
     */
    const_iterator &operator++()
    {
      ++it;
      return *this;
    }

    bool operator==(const const_iterator &other) const { return it == other.it; }
    bool operator!=(const const_iterator &other) const { return it != other.it; }

    friend class LettersSet;
  };

  /**
   * @brief Busca una letra en el conjunto.
   * @param c Carácter a buscar.
   * @return Iterador apuntando a la letra si existe, end() en caso contrario.
   */
  iterator find(char c);

  /**
   * @brief Devuelve un iterador al inicio del conjunto.
   */
  iterator begin();

  /**
   * @brief Devuelve un iterador constante al inicio del conjunto.
   */
  const_iterator begin() const;

  /**
   * @brief Devuelve un iterador al final del conjunto.
   */
  iterator end();

  /**
   * @brief Devuelve un iterador constante al final del conjunto.
   */
  const_iterator end() const;

  /**
   * @brief Calcula la puntuación de una palabra.
   * @param palabra Palabra a evaluar.
   * @return Puntuación total de la palabra.
   */
  int getScore(const string &palabra) const;

  /**
   * @brief Devuelve el número de repeticiones de una letra.
   * @param c Carácter a consultar.
   * @return Número de repeticiones.
   */
  int getOcurrences(char c);

  /**
   * @brief Devuelve el número total de letras en el conjunto.
   * @return Suma de todas las repeticiones.
   */
  int getTotalLetters();

  /**
   * @brief Carga las letras desde un fichero.
   * @param filename Nombre del fichero a leer.
   */
  void loadFromFile(string filename);

  /**
   * @brief Sobrecarga del operador de entrada.
   * @param is Flujo de entrada.
   * @param ltr Conjunto de letras a rellenar.
   * @return Flujo de entrada.
   */
  friend istream &operator>>(istream &is, LettersSet &ltr);

  /**
   * @brief Sobrecarga del operador de salida.
   * @param os Flujo de salida.
   * @param ltr Conjunto de letras a imprimir.
   * @return Flujo de salida.
   */
  friend ostream &operator<<(ostream &os, LettersSet &ltr);
};

#endif
