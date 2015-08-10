#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
#include "parserexception.h"


class Parser
{
public:
    Parser(Lexer lex);
    Lexer Lex;
    Token *CurrentToken;
    void ConsumeToken();
    void Parse();


private:
    typedef map<string,TokenType> Map;
    Map TypeWords;
    void InitializeTypeWords();
    Map StatementWords;
    void InitializeStatementWords();

    void Program_Code();
    void Lpp_Program();
    void Program_Header();
    void Types_List();
    void Types_Structure();
    void Type();
    void Declare_Variables();
    void Variables_Group();
    void ID_List();
    void Array_Size();
    void Integer_List();
    void Methods_List();
    void Method();
    void Method_Body();
    void Params_List();
    void Declare_Params();
    void Param_Group();
    void Param();

    void Statement_List();
    void Statement();
    void Statement_Si();
    void Statement_Sino();
    void Statement_SinoP();
    void Statement_Para();
    void Variable();
    void Simple_Variable();
    void Compuest_Variable();
};

#endif // PARSER_H
