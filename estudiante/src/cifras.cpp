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
        const auto &hojas = soluciones.getSoluciones();
        if (hojas.empty())
            return -1;

        int solucionCercana = hojas.front()->etiqueta;
        int diffMin = abs(solucionCercana - objetivo);

        for (auto n : hojas)
        {
            int diff = abs(n->etiqueta - objetivo);
            if (diff < diffMin)
            {
                diffMin = diff;
                solucionCercana = n->etiqueta;
            }
        }
        return solucionCercana;
    }

    void obtenerCamino(int numero)
    {
        string camino = soluciones.mostrarSolucion(numero);
        cout << "Camino para \n"
             << numero << ": " << camino << endl;
    }
    void generarSoluciones()
    {
        soluciones = ArbolCifras(numeros);
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
        advance(it, aleatorio);
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
         << "voy a calcular todas las soluciones..." << endl;

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
