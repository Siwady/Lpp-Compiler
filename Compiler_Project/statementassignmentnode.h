#ifndef STATEMENTASSIGNMENTNODE_H
#define STATEMENTASSIGNMENTNODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "expressionnode.h"
#include "helper.h"

class StatementAssignmentNode : public StatementNode
{
public:
    VariableNode* Variable;
    ExpressionNode* Expression;
    StatementAssignmentNode(VariableNode* var,ExpressionNode* expr);

    // StatementNode interface
public:
    string ToXML(int i);
};

#endif // STATEMENTASSIGNMENTNODE_H
