#include "token.h"

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
        case Html: return "Html";break;
        //ReservedWords
        case entero: return "Entero";break;
        case real: return "Real";break;
        case caracter: return "Caracter";break;
        case booleano: return "Booleano";break;
        case cadena: return "Cadena";break;
        case inicio: return "inicio";break;
        case fin: return "fin";break;
        case escriba: return "escriba";break;
        case entonces: return "entonces";break;
        case Op_Assignment: return "Op_Assignment";break;
        case Op_Div: return "Op_Div";break;
        case Op_Exp: return "Op_Exp";break;
        case Op_GreaterOrEqualThan: return "Op_GreaterOrEqualThan";break;
        case Op_GreaterThan: return "Op_GreaterThan";break;
        case Op_LessOrEqualThan: return "Op_LessOrEqualThan";break;
        case Op_LessThan: return "Op_LessThan";break;
        case Op_LogicalO: return "Op_LogicalO";break;
        case Op_LogicalY: return "Op_LogicalY";break;
        case Op_Mult: return "Op_Mult";break;
        case Op_Sub: return "Op_Sub";break;
        case Op_Sum: return "Op_Sum";break;
        case mod: return "mod";break;
        case Div: return "Div";break;
        case colon: return "colon";break;
        case Equal: return "Equal";break;
        case llamar: return "llamar";break;
        case si: return "si";break;
        case sino: return "sino";break;
        case caso: return "caso";break;
        case mientras: return "mientras";break;
        case para: return "para";break;
        case hasta: return "hasta";break;
        case haga: return "haga";break;
        case repita: return "repita";break;
        case procedimiento: return "procedimiento";break;
        case funcion: return "funcion";break;
        case retorne: return "retorne";break;
        case registro: return "registro";break;
        case arreglo: return "arreglo";break;
        case de: return "de";break;
        case tipo: return "tipo";break;
        case abrir: return "abrir";break;
        case cerrar: return "cerrar";break;
        case escribir: return "escribir";break;
        case leer: return "leer";break;
        case verdadero: return "verdadero";break;
        case falso: return "falso";break;
        case es: return "es";break;
        case archivo: return "archivo";break;
        case como: return "como";break;
        case secuencial: return "secuencial";break;
        case lectura: return "lectura";break;
        case escritura: return "escritura";break;
        case LeftParent: return "LeftParent";break;
        case RightParent: return "RightParent";break;
        case comma: return "comma";break;
        case LeftBrackets: return "LeftBrackets";break;
        case RightBrackets: return "RightBrackets";break;
        case dot: return "dot";break;
        case no: return "no";break;
        case Const_cadena: return "Const_cadena";break;
        case Const_caracter: return "Const_caracter";break;
        case Const_entero: return "Const_entero";break;
        case Const_real: return "Const_real";break;
        case Op_NotEqual: return "Op_NotEqual";break;
        case var: return "var";break;
        case declarar: return "declarar";break;
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


