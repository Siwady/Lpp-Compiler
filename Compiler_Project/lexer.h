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
    typedef map<string,TokenType> Map;
    Map ReserverdWords;
    Map PunctualSymbols;
    char GetCurrentSymbol();
    char GetNextSymbol();
    void InitializeReservedWords();
    void InitializePunctualSymbols();
    bool Contains(Map maps,string lexeme);
    bool isHtml;
    Token *GetHTMLToken();
    Token *GetLppToken();
    string ToLowerCase(string word);
};


#endif // LEXER_H
