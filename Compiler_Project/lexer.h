#ifndef LEXER_H
#define LEXER_H
#include "token.h"
#include <map>
#include <iostream>
#include "lexicalexception.h"
#include <iterator>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

class Lexer
{
public:
    Lexer(string input);
    Lexer();
    ~Lexer();

    string Input;
    Token *GetToken();


private:
    char Symbol;
    int Position;
    int Column;
    int Row;
    map<string,TokenType> ReserverdWords;
    char GetCurrentSymbol();
    char GetNextSymbol();
    void InitializeReservedWords();
    bool Contains(string lexeme);

};


#endif // LEXER_H
