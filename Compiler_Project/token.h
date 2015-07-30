#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

enum TokenType{
    Eof,
    Id,
    Error,
    Html,

    Op_Sum,
    Op_Div,
    Op_Sub,
    Op_Mult,
    Op_LogicalY,
    Op_LogicalO,
    Op_Exp,
    Op_Assignment,
    Op_GreaterThan,
    Op_LessThan,
    Op_GreaterOrEqualThan,
    Op_LessOrEqualThan,
    mod,
    Div,

    colon,
    Equal,
    LeftParent,
    RightParent,

    entero,
    Const_entero,
    real,
    Const_real,
    caracter,
    Const_caracter,
    booleano,
    entonces,
    Const_cadena,
    cadena,
    inicio,
    fin,
    escriba,
    llamar,
    si,
    sino,
    caso,
    mientras,
    para,
    hasta,
    haga,
    repita,
    procedimiento,
    funcion,
    retorne,
    registro,
    arreglo,
    de,
    tipo,
    abrir,
    cerrar,
    escribir,
    verdadero,
    falso,
    nueva_linea,
    LeftBrackets,
    RightBrackets,
    comma,
    es,
    archivo,
    secuencial,
    lectura,
    escritura,
    como,
    no,
    dot
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
