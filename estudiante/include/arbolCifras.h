#ifndef ARBOLCIFRAS_H
#define ARBOLCIFRAS_H

#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <set>
using namespace std;

class ArbolCifras
{
public:
    struct nodo
    {
        int etiqueta = 0;
        char signo = ' ';
        string expresion;
        multiset<int> numeros;
        vector<nodo *> hijos;
        nodo *padre = nullptr;
        nodo() {}
    };

    ArbolCifras();
    ArbolCifras(multiset<int> numeros, int objetivo);
    void generarSolucion(nodo *actual, int objetivo);
    int operar(int operador1, int operador2, char signo);
    vector<nodo *> &getSoluciones();
    string mostrarSolucion(int numero);
    bool combinacionMagica();
private:
    nodo *crearNodo(nodo *padre, int operador1, int operador2, char signo, multiset<int> numeros);

    nodo *raiz;
    set<int> hojas;
    vector<nodo *> soluciones;
};

#endif
