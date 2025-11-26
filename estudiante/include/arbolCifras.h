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
        char operador;
        nodo *padre;
        nodo *hijoIzq;
        nodo *hermano;
        nodo()
        {
            operador1 = 0;
            operador2 = 0;
            operador = ' ';
            padre = hijoIzq = hermano = nullptr;
        }

        nodo(char signo)
        {
            operador1 = 0;
            operador2 = 0;
            operador = signo;
            padre = hijoIzq = hermano = nullptr;
        }
    };

private:
    nodo *raiz;

   nodo* comprobarRamas();
   bool comprobar(nodo &n);
   void insertarIzq(nodo *padre,nodo &n);
   nodo* getHrmnoDrcha(int &contador);
   void insertarDcha(nodo*padre,nodo &hijo);
public:
    ArbolCifras();                
    ArbolCifras(nodo *nodoRaiz);  

    nodo *getRaiz();
    void insertarNodo(nodo &n);
};

#endif
