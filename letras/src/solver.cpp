#include "solver.h"

vector<string> Solver::getSolutions(const vector<char>& available_letters, bool score_game)
{
    vector<string> solution;
    mejorPuntuacion = -1;
    auto it = dictionary.begin();
    while(it != dictionary.end())
    {
        string palabra = *it;

        int puntos = -1;
        if (score_game) puntos = valoraPuntos(available_letters, palabra);
        else puntos = valoraTamanio(available_letters, palabra);

        if (puntos > mejorPuntuacion)
        {
            mejorPuntuacion = puntos;
            solution.clear();
            solution.push_back(palabra);
        } else if (puntos == mejorPuntuacion && puntos != -1)
            solution.push_back(palabra);

        ++it;
    }
    return solution;
}

int Solver::valoraPuntos(const vector<char>& available_letters, const string& palabra)
{
    int puntos = -1;
    bool puedeFormarse = true;

    vector<char> temp_letters = available_letters;

    for(char c : palabra)
    {
        auto it = find(temp_letters.begin(), temp_letters.end(), c);
        if (it == temp_letters.end())
        {
            puedeFormarse = false;
            break;
        } else
            temp_letters.erase(it);
    }

    if (puedeFormarse) puntos = letters_set.getScore(palabra);

    return puntos;
}

int Solver::valoraTamanio(const vector<char>& available_letters, const string& palabra)
{
    int puntos = -1;
    bool puedeFormarse = true;

    vector<char> temp_letters = available_letters;

    for(char c : palabra)
    {
        auto it = find(temp_letters.begin(), temp_letters.end(), c);
        if (it == temp_letters.end())
        {
            puedeFormarse = false;
            break;
        } else
            temp_letters.erase(it);
    }

    if (puedeFormarse) puntos = palabra.size();

    return puntos;
}