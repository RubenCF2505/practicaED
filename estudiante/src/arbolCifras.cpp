#include "../include/arbolCifras.h"

ArbolCifras::ArbolCifras()
{
    raiz = new nodo;
    raiz->etiqueta = 0;
}

ArbolCifras::ArbolCifras(multiset<int> numeros)
{
    raiz = new nodo;
    raiz->etiqueta = 0;
    raiz->numeros = numeros;

    for (int hijo : numeros)
    {
        nodo *nodoHijo = new nodo;
        nodoHijo->etiqueta = hijo;
        nodoHijo->numeros = numeros;
        raiz->hijos.push_back(nodoHijo);
    }

    generarSolucion(raiz);
}

bool comprobarOperacion(int operador1, int operador2, char signo)
{
    bool valida = true;
    if (signo == '-' && operador1 - operador2 < 0)
        valida = false;
    if (signo == '/' && (operador2 == 0 || operador1 % operador2 != 0))
        valida = false;
    if (signo == '/' && operador2 == 0)
        valida = false;
    if (operador1 == 1 || operador2 == 1 && signo == '*')
        valida = false;

    return valida;
}

void ArbolCifras::generarSolucion(nodo *actual)
{
    vector<char> signos = {'+', '-', '*', '/'};
    multiset<int> numeros = actual->numeros;

    if (numeros.size() > 1)
    {
        auto it1 = numeros.begin();
        while (it1 != numeros.end())
        {
            auto it2 = numeros.begin();
            while (it2 != numeros.end())
            {
                if (it1 != it2)
                {
                    for (char signo : signos)
                    {
                        if (comprobarOperacion(*it1, *it2, signo))
                        {
                            nodo *hijo = crearNodo(actual, *it1, *it2, signo, numeros);

                            actual->hijos.push_back(hijo);
                            if (hijo->etiqueta >= 100 && hijo->etiqueta <= 999)
                            {
                                hojas.insert(hijo->etiqueta);
                                soluciones.push_back(hijo);
                            }
                            generarSolucion(hijo);
                        }
                    }
                }

                ++it2;
            }

            ++it1;
        }
    }
}

int ArbolCifras::operar(int operador1, int operador2, char signo)
{
    int resultado = 0;
    switch (signo)
    {
    case '+':
        resultado = operador1 + operador2;
        break;
    case '-':
        resultado = operador1 - operador2;
        break;
    case '*':
        resultado = operador1 * operador2;
        break;
    case '/':
        resultado = operador1 / operador2;
        break;
    }
    return resultado;
}

vector<ArbolCifras::nodo *> &ArbolCifras::getSoluciones()
{
    return soluciones;
}

ArbolCifras::nodo *ArbolCifras::crearNodo(nodo *padre, int operador1, int operador2, char signo, multiset<int> numerosPadre)
{

    int nuevoValor = operar(operador1, operador2, signo);

    nodo *nuevo = new nodo;
    nuevo->etiqueta = nuevoValor;
    nuevo->signo = signo;
    nuevo->numeros = numerosPadre;
    nuevo->padre = padre;
    nuevo->expresion = to_string(operador1) + " " + signo + " " + to_string(operador2);

    auto it1 = nuevo->numeros.find(operador1);
    if (it1 != nuevo->numeros.end())
        nuevo->numeros.erase(it1);
    auto it2 = nuevo->numeros.find(operador2);
    if (it2 != nuevo->numeros.end())
        nuevo->numeros.erase(it2);
    nuevo->numeros.insert(nuevoValor);

    return nuevo;
}

ArbolCifras::nodo *ArbolCifras::buscarNodo(nodo *actual, int objetivo)
{
    if (!actual)
        return nullptr;
    if (actual->etiqueta == objetivo && actual->numeros.size() == 1)
        return actual;

    for (nodo *hijo : actual->hijos)
    {
        nodo *res = buscarNodo(hijo, objetivo);
        if (res)
            return res;
    }
    return nullptr;
}

bool ArbolCifras::obtenerCamino(nodo *hoja, string &solucion)
{
    vector<nodo *> camino;
    nodo *actual = hoja;
    while (actual != nullptr)
    {
        camino.push_back(actual);
        actual = actual->padre;
    }

    solucion = "";
    for (int i = camino.size() - 1; i >= 0; i--)
    {
        string expr = camino[i]->expresion;
        if (expr.find('+') != string::npos || expr.find('-') != string::npos ||
            expr.find('*') != string::npos || expr.find('/') != string::npos)
        {
            if (!solucion.empty())
                solucion += "\n";
            solucion += expr + " = " + to_string(camino[i]->etiqueta);
        }
    }

    return !solucion.empty();
}

string ArbolCifras::obtenerCamino(int objetivo)
{
    nodo *hoja = buscarNodo(raiz, objetivo);
    if (!hoja)
        return "No se encontró camino.";

    string solucion;
    if (obtenerCamino(hoja, solucion))
        return solucion;
    return "No se encontró camino.";
}
