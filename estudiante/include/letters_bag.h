#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "letters_set.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

/**
 * TDA LettersBag
 */
class LettersBag
{
private:
    vector<char> letters;

public:
    /**
     * @brief constructor por defecto de la clase LettersBag
     *
     * Crea un vector vacio de letras
     */
    LettersBag() {};

    /**
     * @brief constructor de la clase LettersBag
     *
     * @param letterSet objeto de la clase LetterSet con map de letras (que tiene la letra y la puntuacion).
     */
    LettersBag(const LettersSet &letterSet);

    /**
     * @brief calcula el tamaño del atributo letters
     *
     * @return devuelve el tamaño de letters
     */
    int size() const;

    /**
     * @brief inserta el char c en el vector letters
     *
     * @param c letra a insertar en el vector
     */

    void insert(char c);

    /**
     * @brief borra el char c del vector letters
     *
     * @param c letra a eliminar del vector
     */
    void erase(char c);

    /**
     * @brief limpia el vector de letras
     */
    void clear();

    /**
     * @brief devuelve si el vector de letras está vacío
     * @return true si esta vacio, sino false.
     */
    bool empty() const;
    /**
     *@brief extrae una letra de la lista general de letras de forma aleatoria
     *
     * @return letra extraida
     */
    char extractLetter();

    /**
     * @brief crea un vector con el numero de letras deseado
     * @param num numero de letras deseadas
     * 
     * @return vector las letras extraidas.
     *
     */
    vector<char> extractLetter(int num);
};

#endif
