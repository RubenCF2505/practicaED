#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <list>
#include <random>
#include "arbolCifras.h"

using namespace std;
const int SIZE = 6;
class Cifras
{
    list<int> bolsa = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 50, 75, 100};
    set<int> numeros;
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

    int getNumero()
    {
        return numero;
    }
    void listar(){
        for(int element:numeros){
            cout<<element<<endl;
        }
    }

private:
    void insertarCifra()
    {
        auto it = bolsa.begin();
        int contador = 0;
        int aleatorio = generarRandom(0, bolsa.size());

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
    srand(time(NULL));

    cout << "JUEGO DE LAS CIFRAS" << endl;
    Cifras juego;

    juego.listar();

    cout << juego.getNumero()<<endl;

}

