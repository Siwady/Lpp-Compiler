#include "parser.h"

Parser::Parser(Lexer lex)
{
    this->Lex=lex;
    InitializeTypeWords();
    ConsumeToken();

}

void Parser::ConsumeToken()
{
    this->CurrentToken = this->Lex.GetToken();
}

void Parser::InitializeTypeWords()
{
    this->TypeWords.insert(make_pair("entero",entero));
    this->TypeWords.insert(make_pair("real",real));
    this->TypeWords.insert(make_pair("booleano",booleano));
    this->TypeWords.insert(make_pair("caracter",caracter));
    this->TypeWords.insert(make_pair("cadena",cadena));
    this->TypeWords.insert(make_pair("arreglo",arreglo));
    this->TypeWords.insert(make_pair("archivo",archivo));
    this->TypeWords.insert(make_pair("id",Id));
}

void Parser::InitializeStatementWords()
{
    this->TypeWords.insert(make_pair("si",si));
    this->TypeWords.insert(make_pair("mientras",mientras));
    this->TypeWords.insert(make_pair("llamar",llamar));
    this->TypeWords.insert(make_pair("caso",caso));
    this->TypeWords.insert(make_pair("abrir",abrir));
    this->TypeWords.insert(make_pair("escribir",escribir));
    this->TypeWords.insert(make_pair("leer",leer));
    this->TypeWords.insert(make_pair("para",para));
    this->TypeWords.insert(make_pair("repita",repita));
    this->TypeWords.insert(make_pair("id",Id));
    this->TypeWords.insert(make_pair("escriba",escriba));
    this->TypeWords.insert(make_pair("cerrar",cerrar));
}

void Parser::Parse()
{
    Program_Code();
    if (CurrentToken->Type != Eof)
    {
        throw ParserException(string("se esperaba EOF,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

void Parser::Program_Code()
{
    if(CurrentToken->Type== tipo ||CurrentToken->Type== registro || Lex.Contains(TypeWords,Lex.ToLowerCase(CurrentToken->Lexeme)) || CurrentToken->Type== procedimiento  ||CurrentToken->Type== funcion)
    {
        Lpp_Program();
        Program_Code();
    }else if(CurrentToken->Type==Html)
    {
        ConsumeToken();
        Program_Code();
    }else
    {
        //Epsilon
    }
}

void Parser::Lpp_Program()
{
    Program_Header();
    Statement_List();
}

void Parser::Program_Header()
{
    if(CurrentToken->Type==tipo || CurrentToken->Type==registro)
    {
        Types_List();
    }else if(Lex.Contains(TypeWords,Lex.ToLowerCase(CurrentToken->Lexeme)))
    {
        Declare_Variables();
    }else if(CurrentToken->Type== procedimiento  ||CurrentToken->Type== funcion)
    {
        Methods_List();
    }else
    {
        //Epsilon
    }
}

void Parser::Types_List()
{
    if(CurrentToken->Type==tipo || CurrentToken->Type==registro)
    {
       Types_Structure();
       Types_List();
    }else
    {
        //Epsilon
    }
}

void Parser::Types_Structure()
{
    if(CurrentToken->Type==tipo)
    {
       ConsumeToken();
       if(CurrentToken->Type==Id)
       {
           ConsumeToken();
           if(CurrentToken->Type==es)
           {
               ConsumeToken();
               if(Lex.Contains(TypeWords,Lex.ToLowerCase(CurrentToken->Lexeme)))
               {
                    Type();
               }else{
                   throw ParserException(string("se esperaba un tipo,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
               }
           }else{
               throw ParserException(string("se esperaba ES,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
           }
       }else{
           throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
       }
    }else if(CurrentToken->Type==registro)
    {
        ConsumeToken();
        if(CurrentToken->Type==Id)
        {
            ConsumeToken();
            if(Lex.Contains(TypeWords,Lex.ToLowerCase(CurrentToken->Lexeme)))
            {
                Declare_Variables();
                if(CurrentToken->Type==fin)
                {
                    ConsumeToken();
                    if(CurrentToken->Type==registro)
                    {
                        ConsumeToken();
                    }else{
                        throw ParserException(string("se esperaba registro,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                    }
                }else{
                    throw ParserException(string("se esperaba fin,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                }
            }else{
                throw ParserException(string("se esperaba un tipo,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        throw ParserException(string("se esperaba Tipo o Registro,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

void Parser::Type()
{
    if(CurrentToken->Type==cadena)
    {
        ConsumeToken();
        if(CurrentToken->Type==LeftBrackets)
        {
            ConsumeToken();
            if(CurrentToken->Type==Const_entero)
            {
                ConsumeToken();
                if(CurrentToken->Type==RightBrackets)
                {
                    ConsumeToken();
                }else{
                    throw ParserException(string("se esperaba ],Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                }
            }else{
                throw ParserException(string("se esperaba una constante entera,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba [,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else if(CurrentToken->Type==arreglo)
    {
        ConsumeToken();
        if(CurrentToken->Type==LeftBrackets)
        {
            ConsumeToken();
            if(CurrentToken->Type==Const_entero)
            {
                Array_Size();
                if(CurrentToken->Type==RightBrackets)
                {
                    ConsumeToken();
                    if(CurrentToken->Type==de)
                    {
                        ConsumeToken();
                        if(Lex.Contains(TypeWords,Lex.ToLowerCase(CurrentToken->Lexeme)))
                        {
                            Type();
                        }else{
                            throw ParserException(string("se esperaba un tipo,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                        }
                    }else{
                        throw ParserException(string("se esperaba {de},Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                    }
                }else{
                    throw ParserException(string("se esperaba ],Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                }
            }else{
                throw ParserException(string("se esperaba una constante entera,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba [,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else if(CurrentToken->Type==archivo)
    {
        ConsumeToken();
        if(CurrentToken->Type==de)
        {
            ConsumeToken();
            if(Lex.Contains(TypeWords,Lex.ToLowerCase(CurrentToken->Lexeme)))
            {
                Type();
            }else{
                throw ParserException(string("se esperaba un tipo,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }
    }else
    {
        ConsumeToken();
    }
}

void Parser::Declare_Variables()
{
    if(Lex.Contains(TypeWords,Lex.ToLowerCase(CurrentToken->Lexeme)))
    {
        Variables_Group();
        Declare_Variables();
    }
    else
    {
        //Epsilon
    }
}

void Parser::Variables_Group()
{
    if(Lex.Contains(TypeWords,Lex.ToLowerCase(CurrentToken->Lexeme)))
    {
        Type();
        if(CurrentToken->Type==Id)
        {
            ConsumeToken();
            ID_List();

        }else{
            throw ParserException(string("se esperaba un Id,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }
}

void Parser::ID_List()
{
    if(CurrentToken->Type==comma)
    {
        ConsumeToken();
        if(CurrentToken->Type==Id)
        {
            ConsumeToken();
            ID_List();
        }else{
            throw ParserException(string("se esperaba un Id,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else
    {
        //Epsilon
    }
}

void Parser::Array_Size()
{
    if(CurrentToken->Type==Const_entero)
    {
        ConsumeToken();
        Integer_List();
    }else{
        throw ParserException(string("se esperaba una constante entera,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

void Parser::Integer_List()
{
    if(CurrentToken->Type==comma)
    {
        ConsumeToken();
        if(CurrentToken->Type==Const_entero)
        {
            ConsumeToken();
            Integer_List();
        }else{
            throw ParserException(string("se esperaba una constante entera,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else
    {
        //Epsilon
    }
}

void Parser::Methods_List()
{
    if(CurrentToken->Type==funcion || CurrentToken->Type==procedimiento)
    {
        Method();
        Declare_Variables();
        Method_Body();
        Methods_List();
    }
}

void Parser::Method()
{
    if(CurrentToken->Type==funcion)
    {
        ConsumeToken();
        if(CurrentToken->Type==Id)
        {
            ConsumeToken();
            Params_List();
            if(CurrentToken->Type==colon)
            {
                ConsumeToken();
                Type();
            }else{
                throw ParserException(string("se esperaba : ,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else if(CurrentToken->Type==procedimiento)
    {
        ConsumeToken();
        if(CurrentToken->Type==Id)
        {
            ConsumeToken();
            Params_List();
        }else{
            throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }
}

void Parser::Method_Body()
{
    if(CurrentToken->Type==inicio)
    {
        ConsumeToken();
        if(Lex.Contains(StatementWords,Lex.ToLowerCase(CurrentToken->Lexeme)))
        {
            Statement_List();
        }else
        {
            //Epsilon
        }
    }else{
        throw ParserException(string("se esperaba Inicio,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

void Parser::Params_List()
{
    if(CurrentToken->Type==LeftParent)
    {
        ConsumeToken();
        Declare_Params();
        if(CurrentToken->Type==RightParent)
        {
            ConsumeToken();
        }else{
           throw ParserException(string("se esperaba ),Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else
    {
        //Epsilon
    }
}

void Parser::Declare_Params()
{
    Param();
    Param_Group();
}

void Parser::Param_Group()
{
    if(CurrentToken->Type==comma)
    {
        ConsumeToken();
        Param();
        Param_Group();
    }else
    {
        //Epsilon
    }
}

void Parser::Param()
{
    if(CurrentToken->Type==var)
    {
        Type();
        if(CurrentToken->Type==Id)
        {
            ConsumeToken();
        }else{
            throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else if(Lex.Contains(TypeWords,Lex.ToLowerCase(CurrentToken->Lexeme)))
    {
        Type();
        if(CurrentToken->Type==Id)
        {
            ConsumeToken();
        }else{
            throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }else{
        throw ParserException(string("se esperaba var o un Tipo de dato,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}


void Parser::Statement_List()
{
    if(Lex.Contains(StatementWords,Lex.ToLowerCase(CurrentToken->Lexeme)))
    {
        Statement();
        Statement_List();
    }else
    {
        //Epsilon
    }
}

void Parser::Statement()
{
    if(CurrentToken->Type==si)
    {
        Statement_Si();
    }else if(CurrentToken->Type==mientras)
    {
        Statement_Mientras();
    }else if(CurrentToken->Type==llamar)
    {
        Statement_Llamar();
    }else if(CurrentToken->Type==caso)
    {
        Statement_Case();
    }else if(CurrentToken->Type==abrir)
    {
        Statement_Abrir_Archivo();
    }else if(CurrentToken->Type==escribir)
    {
        Statement_Escribir_Archivo();
    }else if(CurrentToken->Type==leer)
    {
        Statement_Leer_Archivo();
    }else if(CurrentToken->Type==para)
    {
        Statement_Para();
    }else if(CurrentToken->Type==repita)
    {
        Statement_Repita();
    }else if(CurrentToken->Type==Id)
    {
        Statement_Assignment();
    }else if(CurrentToken->Type==escriba)
    {
        Statement_Escriba();
    }else if(CurrentToken->Type==cerrar)
    {
        Statement_Cerrar_Archivo();
    }
}

void Parser::Statement_Si()
{
    if(CurrentToken->Type==si)
    {
        ConsumeToken();
        Expression();
        if(CurrentToken->Type==entonces)
        {
            ConsumeToken();
            Statement_List();
            Statement_Sino();
            if(CurrentToken->Type==fin)
            {
                ConsumeToken();
                if(CurrentToken->Type==si)
                {
                    ConsumeToken();
                }else{
                    throw ParserException(string("se esperaba si,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                }
            }else{
                throw ParserException(string("se esperaba Fin,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba entonces,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }
}

void Parser::Statement_Sino()
{
    if(CurrentToken->Type==sino)
    {
        ConsumeToken();
        Statement_SinoP();
    }else
    {
        //Epsilon
    }
}

void Parser::Statement_SinoP()
{
    if(CurrentToken->Type==si)
    {
        Statement_Si();
    }else
    {
        Statement_List();
    }
}

void Parser::Statement_Para()
{
    if(CurrentToken->Type==para)
    {
        ConsumeToken();
        Variable();
        if(CurrentToken->Type==Op_Assignment)
        {
            ConsumeToken();
            Expression();
            if(CurrentToken->Type==hasta)
            {
                ConsumeToken();
                Expression();
                if(CurrentToken->Type==haga)
                {
                    ConsumeToken();
                    Statement_List();
                    if(CurrentToken->Type==fin)
                    {
                        ConsumeToken();
                        if(CurrentToken->Type==para)
                        {
                            ConsumeToken();
                        }else{
                            throw ParserException(string("se esperaba Para,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                        }
                    }else{
                        throw ParserException(string("se esperaba Fin,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                    }
                }else{
                    throw ParserException(string("se esperaba Haga,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
                }
            }else{
                throw ParserException(string("se esperaba Hasta,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
            }
        }else{
            throw ParserException(string("se esperaba <-,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
        }
    }
}

void Parser::Variable()
{
    Simple_Variable();
    Compuest_Variable();
}

void Parser::Simple_Variable()
{
    if(CurrentToken->Type==Id)
    {
        ConsumeToken();
        Array_Variable();
    }else
    {
        throw ParserException(string("se esperaba un ID,Fila:")+to_string(CurrentToken->Row)+",Columna:"+to_string(CurrentToken->Column));
    }
}

void Parser::Compuest_Variable()
{

}

