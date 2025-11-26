#ifndef ARBOLCIFRAS_H
#define ARBOLCIFRAS_H

#include <list>
using namespace std;

class ArbolCifras
{
public:
    struct nodo
    {
        int operador1;
        int operador2;
        list<int> numeros;
        char signo;
        nodo *padre;
        nodo *hijoIzq;
        nodo *hermano;
        nodo()
        {
            operador1 = 0;
            operador2 = 0;
            signo = ' ';
            padre = hijoIzq = hermano = nullptr;
        }

        nodo(char signo)
        {
            operador1 = 0;
            operador2 = 0;
            signo = signo;
            padre = hijoIzq = hermano = nullptr;
        }
        nodo(int numero1, int numero2, char signo)
        {
            operador1 = numero1;
            operador2 = numero2;
            signo = signo;
            padre = hijoIzq = hermano = nullptr;
        }
    };

private:
    nodo *raiz;

    nodo *comprobarRamas();
    bool comprobar(nodo &n);
    void insertarIzq(nodo *padre, nodo &n);
    nodo *getHrmnoDrcha(int &contador);
    void insertarDcha(nodo *padre, nodo &hijo);

public:
    ArbolCifras();
    ArbolCifras(nodo *nodoRaiz);

    nodo *getRaiz();
    void insertarNodo(nodo &n);
};

#endif
