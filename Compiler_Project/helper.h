#ifndef HELPER_H
#define HELPER_H

#include "variablenode.h"
#include "literalnode.h"
#include "declarevariablenode.h"
#include "parameternode.h"
#include "casenode.h"
#include <string>
#include <list>
#include "statementnode.h"
#include "structurenode.h"
#include "programcodenode.h"

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
};

#endif // HELPER_H
