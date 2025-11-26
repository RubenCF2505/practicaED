#ifndef ARBOLCIFRAS_H
#define ARBOLCIFRAS_H

#include <set>
using namespace std;

class ArbolCifras
{
public:
    struct nodo
    {
        set<int> numeros;
        nodo *padre;
        nodo *hijoIzq;
        nodo *hermano;
    };

private:
    nodo *raiz;

    nodo *getHrmnoDrcha(nodo *padre);

public:
    ArbolCifras();
    ArbolCifras(set<int> numeros);
    nodo crearNodo(char signo,int operador1,int operador2,nodo padre);
    void insertarHijo(nodo *padre, nodo &hijo);
    void insertarHmno(nodo *padre, nodo &insertar);
    nodo *getRaiz();
};

#endif
