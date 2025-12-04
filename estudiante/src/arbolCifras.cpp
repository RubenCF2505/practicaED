#include "../include/arbolCifras.h"
#include <stack>

ArbolCifras::ArbolCifras()
{
    raiz = new nodo;
    raiz->etiqueta = 0;
}

ArbolCifras::ArbolCifras(multiset<int> numeros, int objetivo)
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

    generarSolucion(raiz, objetivo);
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

    if (operador2 == 1 && signo == '/')
        valida = false;
    if ((signo == '+' || signo == '*') && operador1 > operador2)
        valida = false;

    return valida;
}

bool ArbolCifras::combinacionMagica()
{
    return soluciones.size() == 900;
}

void ArbolCifras::generarSolucion(nodo *actual, int objetivo)
{
    vector<char> signos = {'+', '-', '*', '/'};
    multiset<int> numeros = actual->numeros;
    if (actual->etiqueta != objetivo)
    {

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
                                    if (hojas.find(hijo->etiqueta) == hojas.end())
                                    {
                                        hojas.insert(hijo->etiqueta);
                                        soluciones.push_back(hijo);
                                    }
                                }
                                generarSolucion(hijo, objetivo);
                            }
                        }
                    }

                    ++it2;
                }

                ++it1;
            }
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

string ArbolCifras::mostrarSolucion(int numero)
{
    string solucion;
    auto it = soluciones.begin();
    bool encontrado = false;
    while (it != soluciones.end() && !encontrado)
    {
        if ((*it)->etiqueta == numero)
        {
            stack<string> pasos;
            nodo *actual = *it;

            while (actual->padre != nullptr)
            {
                pasos.push(actual->expresion + " = " + to_string(actual->etiqueta));
                actual = actual->padre;
            }
            while (!pasos.empty())
            {
                solucion += pasos.top() + "\n";
                pasos.pop();
            }
            encontrado = true;
        }
        ++it;
    }
    return solucion;
}