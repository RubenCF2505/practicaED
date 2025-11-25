#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Dictionary {
private:
  set<string> words;

public:
  /**
   * @brief Constructor por defecto
   *
   * Crea un Dictionary vacío
   */
  Dictionary(){};

  /**
   * @brief Destructor
   */
  ~Dictionary(){}

  /**
   *  @brief Limpia el Dictionary
   *
   *  @post el diccionario queda con 0 palabras
   */
  void clear();

  /**
   * @brief Tamaño del diccionario
   *
   * @return Número de palabras guardadas en el diccionario
   */
  unsigned int size() const;

  /**
   * @brief Comprueba si el diccionario está vacio.
   * @return true si el diccionario está vacío, false en caso contrario
   */
  bool empty() const { return words.size() == 0; }

  /**
   * @brief Indica si una palabra esta en el diccionario o no.
   * Este método comprueba si una determinada palabra se encuentra o no en el diccionario
   * @param palabra: la palabra que se quiere buscar.
   * @return Booleano indicando si la palabra existe o no en el diccionario
   */
  bool exists(const string &val);

  /**
   * @brief Elimina una palabra del diccionario
   *
   * @param val Palabra a borrar del diccionario
   *
   * @return Booleano que indica si la palabra se ha borrado del diccionario
   */
  bool erase(const string &val);

  /**
   * @brief Sobrecarga del operador de entrada
   *
   * Permite leer las palabras de un fichero de texto e introducirlas en el
   * diccionario
   * @param is Flujo de entrada
   * @param dic Diccionario a rellenar
   * @return Flujo de entrada para poder encadenar el operador
   */
  friend istream &operator>>(istream &is, Dictionary &dic);

  /**
   * @brief Sobrecarga del operador de salida
   *
   * Permite imprimir el diccionario completo a un flujo de salida
   *
   * @param os Flujo de salida, donde imprimir el diccionario
   * @param dic Diccionario a imprimir
   * @return Flujo de salida, para poder encadenar el operador
   */
  friend ostream &operator<<(ostream &os, const Dictionary &dic);

  /**
   * @brief Indica el numero de apariciones de una letra.
   *
   *
   * @param c letra a buscar.
   * @return Un entero indicando el numero de apariciones.
   */
  int getOccurrences(const char c) const;

  /**
   * @brief Indica el numero totales de letras
   * @return Un entero indicando el numero totales de letras
   */
  int getTotalLetters() const;

  /**
   * @brief Iterador del diccionario. Obtiene las palabras ordenadas alfabéticamente
   */
  class iterator {
  private:
    set<string>::iterator it;

  public:
    friend class Dictionary;
  };

  /**
   * @brief Iterador constante del diccionario. Obtiene las palabras ordenadas alfabéticamente
   */
  class const_iterator {
  private:
    set<string>::const_iterator it;

  public:
    friend class Dictionary;
  };

  /**
   * @brief Indica si una palabra esta en el diccionario
   * @return iterador apuntando a la palabra si esta o end si no esta
   */
  iterator find(const string &w);

  /**
   * @brief Obtiene todas las palabras de una longitud
   * @param longitud: valor de longitud de las palabras a devolver
   * @return un vector con palabras de la longitud dada
   */
  vector<string> getWordsLength(int longitud);

  /**
   * @brief Inserta una palabra en el diccionario
   *
   * @param val palabra a insertar en el diccionario
   * @return Booleano que indica si la inserción ha tenido éxito. Una palabra se inserta
   * con éxito si no existía previamente en el diccionario. El iterador apunta a la palabra
   */
  pair<iterator, bool> insert(const string &val);

  /**
   * @brief Busca las palabras con un prefijo
   *
   * @param val  prefijo a buscar
   * @return un pair con dos iteradores el primero apuntando a la primera palabra con el prefijo y
   * el segundo donde ya no contiene el prefijo. Si no existe el prefijo se devuelven los dos
   * iteradores apuntando a end()
   */
  pair<iterator, iterator> range_prefix(const string &val);

  /**
   * @brief Obtiene el iterador apuntando a la primera palabra del diccionario
   */
  iterator begin();
  const_iterator begin() const;

  /**
   * @brief Obtiene el iterador apuntando al final del diccionario.
   */
  iterator end();
  const_iterator end() const;
};

#endif
