#include "letters_set.h"
#include <iostream>
#include <fstream>

using namespace std;

int LettersSet::size() const
{
    return charSet.size();
}

bool LettersSet::empty() const
{
    return charSet.empty();
}

void LettersSet::clear()
{
    charSet.clear();
}

void LettersSet::insert(char c, int rep, int score)
{
    pair<char, LetterInfo> aux;
    aux.first = c;
    aux.second = LetterInfo(rep, score);

    charSet.insert(aux);
}

void LettersSet::erase(char c)
{
    charSet.erase(c);
}

LetterInfo& LettersSet::operator[](char c)
{
    return charSet[c];
}

LetterInfo LettersSet::operator[](char c) const
{
    auto it = charSet.find(c);
    if (it != charSet.end()) return it->second;
    return LetterInfo(0,0);
}

LettersSet::iterator LettersSet::find(char c)
{
    return iterator(charSet.find(c));
}

LettersSet::iterator LettersSet::begin()
{
    return iterator(charSet.begin());
}

LettersSet::const_iterator LettersSet::begin() const
{
    return const_iterator(charSet.begin());
}

LettersSet::iterator LettersSet::end()
{
    return iterator(charSet.end());
}

LettersSet::const_iterator LettersSet::end() const
{
    return const_iterator(charSet.end());
}

int LettersSet::getScore(const string &palabra) const
{
    int suma = 0;
    for (char c : palabra)
        suma += (*this)[c].score;
    return suma;
}

int LettersSet::getOcurrences(char c)
{
    return (*this)[c].repetitions;
}

int LettersSet::getTotalLetters()
{
    int suma = 0;
    for (pair<const char, LetterInfo> &l : charSet)
        suma += l.second.repetitions;
    return suma;
}

istream &operator>>(istream &is, LettersSet &ltr)
{
    string header;
    getline(is, header);
    
    char letra;
    int rep, score;

    while(is >> letra >> rep >> score)
        ltr.insert(letra, rep, score);

    return is;
}

ostream &operator<<(ostream &os, LettersSet &ltr)
{
    for (pair<const char, LetterInfo> &l : ltr.charSet)
        os << l.first << " " << l.second.repetitions << " " << l.second.score << "\n";
    return os;
}

void LettersSet::loadFromFile(string filename)
{
    ifstream fin(filename);
    if (!fin.is_open()) return;

    fin >> *this;

    fin.close();
}