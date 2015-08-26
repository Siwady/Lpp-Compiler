#ifndef PROCEDURENODE_H
#define PROCEDURENODE_H
#include "statementnode.h"
#include "parameternode.h"
#include "variablenode.h"
#include "statementnode.h"
#include "expressionnode.h"
#include "declarevariablenode.h"

class ProcedureNode : public StatementNode
{
public:
    string ID;
    list<ParameterNode*>* Params;
    list<DeclareVariableNode*>* Variables;
    list<StatementNode*>* Statements;
    ProcedureNode(string id, list<ParameterNode*>* param, list<DeclareVariableNode*>* vars, list<StatementNode*>* statements);
    ProcedureNode();
};

#endif // PROCEDURENODE_H
