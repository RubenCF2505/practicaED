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
        vector<nodo*> hijos;
        nodo* padre = nullptr;
        nodo() {}
    };

    ArbolCifras();
    ArbolCifras(multiset<int> numeros);
    void generarSolucion(nodo *actual);
    int operar(int operador1, int operador2, char signo);
    vector<nodo*>& getSoluciones();
    string obtenerCamino(int objetivo);

private:
    bool obtenerCamino(nodo *hoja, string &solucion);
    nodo* crearNodo(nodo* padre, int operador1, int operador2, char signo, multiset<int> numeros);
    nodo* buscarNodo(nodo* actual, int objetivo);

    nodo* raiz;
    set<int> hojas;
    vector<nodo*> soluciones;
};

#endif
