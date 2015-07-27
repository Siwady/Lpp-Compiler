#include "token.h"
#include <QString>

Token::Token(TokenType type, string lexeme, int column, int row)
{
    this->Type=type;
    this->Lexeme=lexeme;
    this->Column=column;
    this->Row=row;
}

string Token::GetTypeString(TokenType type)
{
    switch(type)
    {
        case Eof: return "EOF";break;
        case Id: return "Id";break;
        case entero: return "Entero";break;
        case real: return "Real";break;
        case caracter: return "Caracter";break;
        case booleano: return "Booleano";break;
        case cadena: return "Cadena";break;

        default: return "Unknown Token";
    }
}

string Token::ToString()
{
    string format="Type:";
    format.append(GetTypeString(this->Type));
    format.append(", Lexeme:");
    format.append(this->Lexeme);
    format.append(", Column:");
    format.append(to_string(this->Column));
    format.append(", Row:");
    format.append(to_string(this->Row));

    return format;
}


