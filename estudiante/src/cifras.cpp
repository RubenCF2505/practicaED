
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <random>
#include "../include/arbolCifras.h"

using namespace std;
const int SIZE = 6;

class Cifras
{
    list<int> bolsa = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 50, 75, 100};
    multiset<int> numeros;
    int numero;
    ArbolCifras soluciones;

public:
    Cifras()
    {

        for (int i = 0; i < SIZE; i++)
        {
            insertarCifra();
        }

        numero = generarRandom(100, 999);
    }

    int getNumero() { return numero; }

    void listar()
    {
        cout << "Números elegidos:" << endl;
        for (int n : numeros)
            cout << n << " ";
        cout << endl;
    }

    bool buscarSolucion(int objetivo)
    {
        for (ArbolCifras::nodo *n : soluciones.getSoluciones())
            if (n->etiqueta == objetivo)
                return true;
        return false;
    }

    int buscarSolucionCercana(int objetivo)
    {
        
        int solucionCercana = soluciones.getSoluciones().front()->etiqueta;
        int restoActual = solucionCercana - objetivo >= 0 ? solucionCercana - objetivo : objetivo - solucionCercana;

        for (ArbolCifras::nodo *nodo : soluciones.getSoluciones())
        {
            int restoNuevo = nodo->etiqueta - objetivo >= 0 ? nodo->etiqueta - objetivo : objetivo - nodo->etiqueta;
            if (restoNuevo < restoActual)
            {
                restoActual = restoNuevo;
                solucionCercana = nodo->etiqueta;
            }
        }
        return solucionCercana;
    }

    void obtenerCamino(int numero)
    {
        string camino = soluciones.mostrarSolucion(numero);
        cout << "Camino para "
             << numero << ": " << "\n"
             << camino << endl;
    }
    void generarSoluciones()
    {
        soluciones = ArbolCifras(numeros, numero);
    }

    bool comprobarSolucionMagica()
    {
        return soluciones.combinacionMagica();
    }

private:
    void insertarCifra()
    {
        auto it = bolsa.begin();
        int aleatorio = generarRandom(0, bolsa.size() - 1);
        int contador = 0;
        while (contador < aleatorio)
        {
            it++;
            contador++;
        }
        numeros.insert(*it);
    }

    int generarRandom(int min, int max)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }
};

int main()
{
    Cifras juego;
    juego.listar();
    cout << "Número objetivo: " << juego.getNumero() << endl;
    cout << endl
         << "voy a calcular la solucion..." << endl;

    juego.generarSoluciones();
    if (juego.comprobarSolucionMagica())
        cout << "!Se trata de una combinación mágica!" << endl;
    if (juego.buscarSolucion(juego.getNumero()))
    {
        cout << "¡Solución encontrada!" << endl;
        juego.obtenerCamino(juego.getNumero());
    }
    else
    {
        int cercana = juego.buscarSolucionCercana(juego.getNumero());
        cout << "La solución más cercana es: " << cercana << endl;
        juego.obtenerCamino(cercana);
    }
}
