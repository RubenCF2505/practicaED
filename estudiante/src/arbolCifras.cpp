#include "arbolCifras.h"

ArbolCifras::ArbolCifras()
{
    raiz = nullptr;
}
ArbolCifras::ArbolCifras(nodo *n)
{
    raiz = n;
}
void ArbolCifras::insertarNodo(nodo &n)
{
    if (!raiz->hijoIzq)
    {
        insertarIzq(raiz, n);
    }
    else
    {
        int contador = 0;
        nodo *aux = getHrmnoDrcha(contador);
        if (contador == 6)
        {
            nodo *padre = aux->padre->hijoIzq;
            insertarIzq(padre, n);
        }
        else
        {
            insertarDcha(aux, n);
        }
    }
}
bool ArbolCifras::comprobar(nodo &n)
{
}
ArbolCifras::nodo *ArbolCifras::getHrmnoDrcha(int &contador)
{
    nodo *aux = raiz->hijoIzq;

    while (aux->hermano != nullptr)
    {
        aux = aux->hermano;
        contador++;
    }
    return aux;
}
ArbolCifras::nodo *ArbolCifras::getRaiz()
{
    return raiz;
}

void ArbolCifras::insertarIzq(nodo *padre, nodo &hijo)
{
    
}

void ArbolCifras::insertarDcha(nodo *padre, nodo &hijo)
{
}

ArbolCifras::nodo *ArbolCifras::comprobarRamas()
{
}