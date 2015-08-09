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

    void Program_Code();
    void Lpp_Program();
    void Program_Header();
    void Types_List();
    void Types_Structure();
    void Type();
    void Declare_Variables();
    void Variables_Group();
    void ID_List();

    void Statement_List();

};

#endif // PARSER_H
