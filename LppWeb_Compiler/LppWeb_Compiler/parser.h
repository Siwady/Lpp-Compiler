#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
#include "parserexception.h"


class Parser
{
public:
    Parser(Lexer* lex);
    Lexer* Lex;
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
    void Arch_Type();
    void Declare();
    void Declare_Variables();
    void Variables_Group();
    void ID_List();
    void Array_Size();
    void Integer_List();
    void Methods_List();
    void Method_Body();
    void Function_Body();
    void Params_List();
    void Declare_Params();
    void Param_Group();
    void Param();

    void Statement_List();
    void Statement();
    void Statement_Return();
    void Statement_Si();
    void Statement_Sino();
    void Statement_SinoP();
    void Statement_Para();
    void Variable();
    void Simple_Variable();
    void Compuest_Variable();
    void Array_Variable();
    void Expression_List();
    void Expression_ListFunctions();
    void Expression_Group();
    void Statement_Mientras();
    void Statement_Repita();
    void Statement_Llamar();
    void Statement_Assignment();
    void Statement_Case();
    void Case_List();
    void Define_Case();
    void Case_Group();
    void Literal_List();
    void Literal_Group();
    void Literal();
    void Sino_Case();
    void Statement_Escriba();
    void Statement_Abrir_Archivo();
    void Operation_List();
    void Operation_Group();
    void Operation();
    void Statement_Cerrar_Archivo();
    void Statement_Escribir_Archivo();
    void Statement_Leer_Archivo();
    void Variable_List();
    void Expression();
    void ExpressionP();
    void Bool_Expression();
    void Bool_ExpressionP();
    void Basic_Expression();
    void Basic_ExpressionP();
    void Factor();
    void FactorP();
    void Exp_Op();
    void Exp_OpP();
    void LogicalNot();

    void Term();
    void Id_Term();
    void Variable_Factor();
    void Const_Negative();
};

#endif // PARSER_H
