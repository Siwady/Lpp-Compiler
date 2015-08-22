#ifndef LEXER_H
#define LEXER_H
#include "token.h"
#include <map>
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
    typedef map<string,TokenType> Map;
    string Input;
    Token *GetToken();
    bool Contains(Map maps,string lexeme);
    string ToLowerCase(string word);

private:
    char Symbol;
    int Position;
    int Column;
    int Row;

    Map ReserverdWords;
    Map PunctualSymbols;
    char GetCurrentSymbol();
    char GetNextSymbol();
    void InitializeReservedWords();
    void InitializePunctualSymbols();

    bool isHtml;
    Token *GetHTMLToken();
    Token *GetLppToken();

};


#endif // LEXER_H
