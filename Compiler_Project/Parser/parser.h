#ifndef PARSER_H
#define PARSER_H
#include "Lexer/lexer.h"
#include "parserexception.h"
#include "Parser/Expressions/expressionnode.h"
#include "Parser/Expressions/Literals/idnode.h"
#include "Parser/Expressions/Literals/cadenanode.h"
#include "Parser/Expressions/Literals/enteronode.h"
#include "Parser/Expressions/Literals/caracternode.h"
#include "Parser/Expressions/Literals/realnode.h"
#include "Parser/Expressions/Literals/boolnode.h"
#include "Parser/Expressions/expressiongroupnode.h"
#include "Parser/Expressions/expressionfunctionnode.h"
#include "Parser/Expressions/Variables/simplevariablenode.h"
#include "Parser/Expressions/Variables/variablenode.h"
#include "Parser/Expressions/Variables/arrayvariablenode.h"
#include "Parser/Expressions/Variables/registervariablenode.h"
#include "Parser/Expressions/Literals/negativenumbernode.h"
#include "Parser/Expressions/Operations/logicalnotnode.h"
#include "Parser/Expressions/Operations/exponentialnode.h"
#include "Parser/Expressions/Operations/integerdivisionnode.h"
#include "Parser/Expressions/Operations/multiplicationnode.h"
#include "Parser/Expressions/Operations/divisionnode.h"
#include "Parser/Expressions/Operations/modnode.h"
#include "Parser/Expressions/Operations/sumnode.h"
#include "Parser/Expressions/Operations/subtractionnode.h"
#include "Parser/Expressions/Operations/lessthannode.h"
#include "Parser/Expressions/Operations/lessandequalthannode.h"
#include "Parser/Expressions/Operations/greaterthannode.h"
#include "Parser/Expressions/Operations/greaterandequalthannode.h"
#include "Parser/Expressions/Operations/equalnode.h"
#include "Parser/Expressions/Operations/notequalnode.h"
#include "Parser/Expressions/Operations/logicalonode.h"
#include "Parser/Expressions/Operations/logicalynode.h"
#include "Parser/Statements/statementnode.h"
#include "Parser/Statements/statementleerarchivonode.h"
#include "Parser/Statements/statementescribirarchivonode.h"
#include "Parser/Statements/statementcerrararchivonode.h"
#include "Parser/Statements/statementabrirarchivonode.h"
#include "Parser/Statements/statementescribanode.h"
#include "Parser/Statements/statementassignmentnode.h"
#include "Parser/Statements/statementllamarnode.h"
#include "Parser/Statements/statementrepitanode.h"
#include "Parser/Statements/statementmientrasnode.h"
#include "Parser/Statements/statementparanode.h"
#include "Parser/Statements/statementreturnnode.h"
#include "Parser/Statements/parameternode.h"
#include "Parser/Statements/functionnode.h"
#include "Parser/Statements/procedurenode.h"
#include "Parser/Header/simpetypenode.h"
#include "Parser/Header/cadenatypenode.h"
#include "Parser/Header/arraytypenode.h"
#include "Parser/Header/archivotypenode.h"
#include "Parser/Header/typestructurenode.h"
#include "Parser/Header/registerstructurenode.h"
#include "Parser/Statements/statementsinode.h"
#include "Parser/Statements/casenode.h"
#include "Parser/Statements/statementcasonode.h"
#include "Parser/Header/typeheadernode.h"
#include "Parser/Header/declareheadernode.h"
#include "lppprogram.h"
#include "Parser/Expressions/Literals/htmlnode.h"

class Parser
{
public:
    Lexer* Lex;
    Parser(Lexer* lex);

    Token *CurrentToken;
    void ConsumeToken();
    list<ProgramCodeNode *> *Parse();


private:
    typedef map<string,TokenType> Map;
    Map TypeWords;
    void InitializeTypeWords();
    Map StatementWords;
    void InitializeStatementWords();

    list<ProgramCodeNode *> *Program_Code(list<ProgramCodeNode *> *ls);
    LppProgram *Lpp_Program();
    ProgramHeaderNode *Program_Header();
    list<StructureNode *> *Types_List(list<StructureNode *> *ls); //ya
    StructureNode *Types_Structure();//ya
    TypeNode* Type();//ya
    TypeNode *Arch_Type();//ya
    list<DeclareVariableNode *> *Declare(list<DeclareVariableNode *> *ls);//ya
    DeclareVariableNode *Declare_Variables();//ya
    DeclareVariableNode *Variables_Group();//ya
    list<string> *ID_List(list<string> *ls); //ya
    list<int> *Array_Size();//ya
    list<int>* Integer_List(list<int> *ls);//ya
    ProgramHeaderNode *Methods_List();//ya
    list<StatementNode*>* Method_Body();//ya
    //void Function_Body();
    list<ParameterNode*>* Params_List(); //ya
    list<ParameterNode*>* Declare_Params();// ya
    list<ParameterNode*>* Param_Group(list<ParameterNode *> *ls);//ya
    ParameterNode* Param();//ya

    list<StatementNode*> *Statement_List(list<StatementNode *> *sl);//ya
    StatementNode* Statement(); //ya
    StatementNode* Statement_Return();//ya
    StatementNode* Statement_Si();
    list<StatementNode *> *Statement_Sino(list<StatementNode *> *ls); //ya
    list<StatementNode*>* Statement_SinoP(list<StatementNode *> *ls); //ya
    StatementNode* Statement_Para();// ya
    VariableNode *Variable();//ya
    VariableNode *Simple_Variable(); //ya
    VariableNode *Compuest_Variable(VariableNode *expressionNode); //ya
    VariableNode *Array_Variable(string id); //ya
    list<ExpressionNode *> *Expression_List(); //ya
    list<ExpressionNode *> *Expression_ListFunctions(string id); //ya
    list<ExpressionNode *> *Expression_Group(list<ExpressionNode *> *ls); //ya
    StatementNode* Statement_Mientras();//ya
    StatementNode* Statement_Repita(); //ya
    StatementNode* Statement_Llamar();//ya
    StatementNode* Statement_Assignment();//ya
    StatementNode *Statement_Case(); //ya
    list<CaseNode *> *Case_List(); //ya
    CaseNode *Define_Case();//ya
    list<CaseNode *> *Case_Group(list<CaseNode *> *ls); //ya
    list<LiteralNode *> *Literal_List();
    list<LiteralNode *> *Literal_Group(list<LiteralNode *> *ls);//ya
    LiteralNode *Literal();//ya
    list<StatementNode *> *Sino_Case();//ya
    StatementNode* Statement_Escriba(); //ya
    StatementNode* Statement_Abrir_Archivo();//ya
    list<string> *Operation_List();//ya
    string Operation_Group();// ya
    string Operation(); //ya
    StatementNode* Statement_Cerrar_Archivo();// ya
    StatementNode* Statement_Escribir_Archivo();//ya
    StatementNode* Statement_Leer_Archivo();//ya
    list<VariableNode *> *Variable_List(list<VariableNode *> *var); //ya
    ExpressionNode *Expression();//ya
    ExpressionNode* ExpressionP(ExpressionNode* node);//ya
    ExpressionNode* Bool_Expression();//ya
    ExpressionNode* Bool_ExpressionP(ExpressionNode *node);//ya
    ExpressionNode* Basic_Expression();//ya
    ExpressionNode* Basic_ExpressionP(ExpressionNode* node);//ya
    ExpressionNode* Factor();//ya
    ExpressionNode* FactorP(ExpressionNode* node);//ya
    ExpressionNode* Exp_Op();//ya
    ExpressionNode* Exp_OpP(ExpressionNode* node);//ya
    ExpressionNode* LogicalNot();//ya

    ExpressionNode* Term(); //ya
    ExpressionNode* Id_Term(string id); //ya
    ExpressionNode* Variable_Factor(string id); //ya
    ExpressionNode* Const_Negative(); //ya
};

#endif // PARSER_H
