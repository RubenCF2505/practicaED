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
        int contador = 1;
        nodo *aux = getHrmnoDrcha(contador);
        if (contador )
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
    bool fin=false;
    bool encontrado=false;
    nodo *padre=raiz;
    while(!encontrado||fin){
        if(raiz->hijoIzq){}
    }

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
    nodo *insertar = &hijo;
    insertar->padre = padre;
    padre->hijoIzq = insertar;
}

void ArbolCifras::insertarDcha(nodo *hermano, nodo &hijo)
{
    nodo *insertar=&hijo;
    insertar->hermano=hermano;
    insertar->padre=hermano->padre;
    
}

ArbolCifras::nodo *ArbolCifras::comprobarRamas()
{
}