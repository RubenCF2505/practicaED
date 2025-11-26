#include "arbolCifras.h"

ArbolCifras::ArbolCifras()
{
    raiz = nullptr;
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
        }else{
            insertarDcha(aux,n);
        }
    }
}
bool ArbolCifras::comprobar(nodo &n)
{
}
ArbolCifras::nodo *ArbolCifras::getHrmnoDrcha(int &contador)
{
}
ArbolCifras::nodo *ArbolCifras::getRaiz()
{
    return raiz;
}

void ArbolCifras::insertarIzq(nodo* padre,nodo &hijo){
    
}

void ArbolCifras::insertarDcha(nodo* padre,nodo &hijo){
    
}
ArbolCifras::ArbolCifras(nodo *n)
{
    raiz = n;
}

ArbolCifras::nodo *ArbolCifras::comprobarRamas()
{
}