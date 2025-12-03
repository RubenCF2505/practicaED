#include "dictionary.h"

void Dictionary::clear()
{
    palabras.clear();
}

unsigned int Dictionary::size() const
{
    return palabras.size();
}

bool Dictionary::empty() const
{
    return palabras.size() == 0;
}

bool Dictionary::exists(const string &val)
{
    return palabras.count(val);
}

bool Dictionary::erase(const string &val)
{
    if(palabras.erase(val)) return true;
    else return false;
}

istream &operator>>(istream &is, Dictionary &dic)
{
    string palabra;
    while(is >> palabra) dic.palabras.insert(palabra);
    return is;
}

ostream &operator<<(ostream &os, const Dictionary &dic)
{
    for (const auto &p : dic.palabras)
        os << p << "\n";
    return os;
}

int Dictionary::getOccurrences(const char c) const
{
    int suma = 0;
    for (const auto &pal : palabras)
        for (char ch : pal)
            if (ch == c)
                suma++;
    return suma;
}

int Dictionary::getTotalLetters() const
{
    int suma = 0;
    for (const auto &pal : palabras)
        suma += pal.size();
    return suma;
}

// ********** Implementación Iterador *****************************************

Dictionary::iterator Dictionary::find(const string &w)
{
    auto it = palabras.find(w);
    return iterator(it);
}

vector<string> Dictionary::getWordsLength(int longitud)
{
    vector<string> final;
    for (const auto &pal : palabras)
        if (pal.size() == longitud)
            final.push_back(pal);
    return final;
}

pair<Dictionary::iterator, bool> Dictionary::insert(const string &val)
{
    auto result = palabras.insert(val);
    return { iterator(result.first), result.second };
}

pair<Dictionary::iterator, Dictionary::iterator> Dictionary::range_prefix(const string &val)
{
    auto ini = palabras.lower_bound(val);

    string strFinal = val;
    strFinal.back()++;  // Aumenta el ultimo caracter
    auto fin = palabras.lower_bound(strFinal);

    return { iterator(ini), iterator(fin) };
}

Dictionary::iterator Dictionary::begin() 
{
    return iterator(palabras.begin());
}

Dictionary::const_iterator Dictionary::begin() const
{
    return const_iterator(palabras.begin());
}

Dictionary::iterator Dictionary::end()
{
    return iterator(palabras.end());
}

Dictionary::const_iterator Dictionary::end() const
{
    return const_iterator(palabras.end());
}