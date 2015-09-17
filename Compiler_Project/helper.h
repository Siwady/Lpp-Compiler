#ifndef HELPER_H
#define HELPER_H

#include "Parser/Expressions/Variables/variablenode.h"
#include "Parser/Expressions/Literals/literalnode.h"
#include "Parser/Expressions/Variables/declarevariablenode.h"
#include "Parser/Statements/parameternode.h"
#include "Parser/Statements/casenode.h"
#include <string>
#include <list>
#include "Parser/Statements/statementnode.h"
#include "Parser/Header/structurenode.h"
#include "Parser/programcodenode.h"
#include "Semantic/semanticexception.h"
#include "Semantic/Type/arreglotype.h"
#include "Semantic/Type/booleantype.h"
#include "Semantic/Type/cadenatype.h"
#include "Semantic/Type/caractertype.h"
#include "Semantic/Type/enterotype.h"
#include "Semantic/Type/realtype.h"
#include "Semantic/Type/negativenumbertype.h"
#include "Semantic/Type/literalcadena.h"
#include "Semantic/Type/archivotype.h"
#include "Parser/Header/archivotypenode.h"
#include "Parser/Header/arraytypenode.h"
#include "Parser/Header/cadenatypenode.h"

using namespace std;
class ParameterNode;
class DeclareVariableNode;
class CaseNode;
class Helper
{
private:
    Helper();
public:
    static StatementNode* GetElementStatementNode(list<StatementNode*> *ls, int i);
    static ExpressionNode *GetElementExpressionNode(list<ExpressionNode*> *ls, int i);
    static VariableNode* GetElementVariableNode(list<VariableNode*> *ls, int i);
    static LiteralNode *GetElementLiteralNode(list<LiteralNode*> *ls, int i);
    static StructureNode *GetElementStructureNode(list<StructureNode*> *ls, int i);
    static DeclareVariableNode *GetElementDeclareVariableNode(list<DeclareVariableNode*> *ls, int i);
    static string GetElementString(list<string> *ls, int i);
    static int GetElementInt(list<int> *ls, int i);
    static ParameterNode *GetElementParameterNode(list< ParameterNode * > *ls, int i);
    static CaseNode *GetElementCaseNode(list<CaseNode*> *ls, int i);
    static ProgramCodeNode *GetElementProgramCodeNode(list<ProgramCodeNode*> *ls, int i);
    static string GetIdentation(int i);
    static Type* GetTypeFromTypeNode(TypeNode* type);
};

#endif // HELPER_H
