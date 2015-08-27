#ifndef STATEMENTASSIGNMENTNODE_H
#define STATEMENTASSIGNMENTNODE_H
#include "statementnode.h"
#include "variablenode.h"
#include "expressionnode.h"

class StatementAssignmentNode : public StatementNode
{
public:
    VariableNode* Variable;
    ExpressionNode* Expression;
    StatementAssignmentNode(VariableNode* var,ExpressionNode* expr);
};

#endif // STATEMENTASSIGNMENTNODE_H
