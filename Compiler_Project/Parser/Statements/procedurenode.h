#ifndef PROCEDURENODE_H
#define PROCEDURENODE_H
#include "statementnode.h"
#include "parameternode.h"
#include "Parser/Expressions/Variables/variablenode.h"
#include "statementnode.h"
#include "Parser/Expressions/expressionnode.h"
#include "Parser/Expressions/Variables/declarevariablenode.h"
#include "Parser/Header/programheadernode.h"
class ProcedureNode : public ProgramHeaderNode
{
public:
    string ID;
    list<ParameterNode*>* Params;
    list<DeclareVariableNode*>* Variables;
    list<StatementNode*>* Statements;
    ProcedureNode(string id, list<ParameterNode*>* param, list<DeclareVariableNode*>* vars, list<StatementNode*>* statements,int row,int column);
    ProcedureNode();

    // ProgramHeaderNode interface
public:
    string ToXML(int i);
};

#endif // PROCEDURENODE_H
