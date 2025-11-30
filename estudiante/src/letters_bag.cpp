#include "letters_bag.h"
#include <cstdlib>   // rand, srand
#include <ctime>     // time

LettersBag::LettersBag(const LettersSet &letterSet)
{
    srand(time(0));
    for (auto it = letterSet.begin(); it != letterSet.end(); ++it)
    {
        auto l = *it;
        char c = l.first;
        for (int i=0; i < l.second.repetitions; i++)
            letters.push_back(c);
    }
}

int LettersBag::size() const
{
    return letters.size();
}

void LettersBag::insert(char c)
{
    letters.push_back(c);
}

void LettersBag::erase(char c)
{
    auto it = letters.begin();
    bool encontrado = false;

    while(it != letters.end() && !encontrado)
    {
        if (*it == c) {
            letters.erase(it);
            encontrado = true;
        }
    }
}

void LettersBag::clear()
{
    letters.clear();
}

bool LettersBag::empty() const
{
    return letters.empty();
}



char LettersBag::extractLetter()
{
    if (letters.empty()) return '\0';

    int pos = rand() % letters.size();
    char c = letters[pos];

    letters.erase(letters.begin() + pos);

    return c;
}

vector<char> LettersBag::extractLetter(int num)
{
    vector<char> aux;
    int count = 0;

    while(count != num && !letters.empty())
        aux.push_back(extractLetter());

    return aux;
}