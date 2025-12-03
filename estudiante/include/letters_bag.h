#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "letters_set.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;


class LettersBag {
private:
    vector<char> letters;
public:
    LettersBag(const LettersSet &letterSet);

    int size();
    void insert(char c);
    void erase(char c);
    void clear();
    bool empty();

    char extractLetter();
    vector<char> extractLetter(int num);
};

#endif
