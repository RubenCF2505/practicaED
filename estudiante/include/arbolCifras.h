#ifndef ARBOLCIFRAS_H
#define ARBOLCIFRAS_H

#include <set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class ArbolCifras
{
public:
    struct nodo
    {
        int etiqueta = 0;
        string expresion;
        multiset<int> numeros;
        vector<nodo *> hijos;
        nodo *padre = nullptr;
        nodo() {}
    };

    /**
     * @brief Constructor por defecto.
     *
     * Crea un ArbolCifras vacío con un nodo raíz inicializado.
     */
    ArbolCifras();

    /**
     * @brief Constructor con parámetros.
     *
     * @param numeros Conjunto de números iniciales.
     * @param objetivo Número que se quiere alcanzar.
     *
     * Construye el árbol generando todas las combinaciones posibles
     * mediante operaciones entre los números.
     */
    ArbolCifras(multiset<int> numeros, int objetivo);

    /**
     * @brief Genera de manera recursiva las posibles soluciones del árbol.
     *
     * A partir del nodo indicado, combina los números mediante operaciones
     * básicas y genera nuevos nodos hijos hasta encontrar el objetivo o
     * agotar combinaciones.
     *
     * @param actual Nodo desde el cual generar los hijos.
     * @param objetivo Valor que se desea obtener.
     *
     * @return Cadena que representa el camino de la solución,
     * o cadena vacía si no se encuentra solución desde ese nodo.
     */
    string generarSolucion(nodo *actual, int objetivo);

    /**
     * @brief Devuelve la lista de nodos que representan soluciones válidas.
     *
     * @return Referencia al vector de nodos solución.
     */
    vector<nodo *> &getSoluciones();

    /**
     * @brief Devuelve los pasos necesarios para alcanzar un objetivo concreto.
     *
     * Busca el nodo que contiene el objetivo, reconstruye el camino
     * desde dicho nodo hasta la raíz y devuelve la secuencia de operaciones.
     *
     * @param objetivo Número objetivo que se quiere alcanzar.
     * @return Cadena con los pasos de la solución.
     */
    string mostrarSolucion(int objetivo);

    /**
     * @brief Comprueba si la combinación de números es mágica.
     *
     * Se considera combinación mágica si con los números iniciales se puede
     * obtener cualquier número de tres cifras.
     *
     * @return `true` si es una combinación mágica, `false` en caso contrario.
     */
    bool combinacionMagica();

private:
    /**
     * @brief Realiza una operación entre dos números.
     *
     * @param operador1 Primer operando.
     * @param operador2 Segundo operando.
     * @param signo Operación a realizar (+, -, *, /).
     *
     * @return Resultado de la operación.
     */
    int operar(int operador1, int operador2, char signo);

    /**
     * @brief Crea un nodo hijo con los valores actualizados tras operar dos números.
     *
     * @param padre Nodo padre del nuevo nodo.
     * @param operador1 Primer número a operar.
     * @param operador2 Segundo número a operar.
     * @param signo Signo de la operación.
     * @param numeros Conjunto de números pertenecientes al nodo padre.
     *
     * @return Puntero al nuevo nodo hijo.
     */
    nodo *crearNodo(nodo *padre, int operador1, int operador2, char signo, multiset<int> numeros);

    /**
     * @brief Nodo raíz del árbol.
     */
    nodo *raiz;

    /**
     * @brief Lista de nodos que representan soluciones encontradas.
     */
    vector<nodo *> soluciones;
};

#endif
