#ifndef LEXER_H
#define LEXER_H
#include "token.h"
#include <map>
#include <iostream>
#include "lexicalexception.h"

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
    map<TokenType,string> ReserverdWords;
    char GetCurrentSymbol();
    char GetNextSymbol();
    void InitializeReservedWords();
    void Contains(string token);

};


#endif // LEXER_H
