#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

enum TokenType{
    Eof,Id,

    //Operators
    Op_Sum,Op_Div,Op_Sub,Op_Mult,Op_LogicalY,Op_LogicalO, Op_Exp,
    //Reserved Words
    entero,real,caracter,booleano,cadena, inicio,fin, escriba,
    //Punctuation Symbols

    //Literal

};

class Token
{
public:
    Token(TokenType type,string lexeme,int column,int row);
    Token(){}
    ~Token(){}
    TokenType Type;
    string Lexeme;
    int Column;
    int Row;
    string GetTypeString(TokenType type);
    string ToString();
};


#endif // TOKEN_H
