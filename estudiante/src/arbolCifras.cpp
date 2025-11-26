#include "arbolCifras.h"

ArbolCifras::ArbolCifras()
{
    raiz = nullptr;
}
ArbolCifras::ArbolCifras(set<int> numeros)
{
    raiz->numeros = numeros;
    raiz->hermano,
        raiz->hijoIzq,
        raiz->padre = nullptr;
}

void ArbolCifras::insertarHijo(nodo *padre, nodo &hijo)
{

    nodo *aux = &hijo;
    aux->padre = padre;
    padre->hijoIzq = aux;
}
void ArbolCifras::insertarHmno(nodo *padre, nodo &insertar)
{

    nodo *nodoHijo = &insertar;
    nodo *hermano = getHrmnoDrcha(padre);
    nodoHijo->hermano = hermano;
    nodoHijo->padre = hermano->padre;
}
ArbolCifras::nodo ArbolCifras::crearNodo(char signo, int operador1, int operador2, nodo padre)
{

    nodo resultado;
    resultado.numeros = padre.numeros;

    switch (signo)
    {
    case '+':
        resultado.numeros.erase(operador1);
        resultado.numeros.erase(operador2);
        resultado.numeros.insert(operador1 + operador2);
        break;

    case '-':
        if (operador1 - operador2 >= 0)
        {
            resultado.numeros.erase(operador1);
            resultado.numeros.erase(operador2);
            resultado.numeros.insert(operador1 - operador2);
        }
        break;
    case '*':
        resultado.numeros.erase(operador1);
        resultado.numeros.erase(operador2);
        resultado.numeros.insert(operador1 * operador2);
        break;
    case '/':
        if (operador1 % operador2 == 0)
        {
            resultado.numeros.erase(operador1);
            resultado.numeros.erase(operador2);
            resultado.numeros.insert(operador1 / operador2);
        }
        break;
    }
    return resultado;
}

ArbolCifras::nodo *ArbolCifras::getHrmnoDrcha(nodo *padre)
{
    nodo *aux = padre->hijoIzq;

    while (aux->hermano != nullptr)
    {
        aux = aux->hermano;
    }
    return aux;
}

ArbolCifras::nodo *ArbolCifras::getRaiz()
{
    return raiz;
}
