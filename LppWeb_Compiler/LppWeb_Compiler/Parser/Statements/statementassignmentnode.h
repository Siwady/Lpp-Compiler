#ifndef STATEMENTASSIGNMENTNODE_H
#define STATEMENTASSIGNMENTNODE_H
#include "statementnode.h"
#include "../Expressions/Variables/variablenode.h"
#include "../Expressions/expressionnode.h"

class StatementAssignmentNode : public StatementNode
{
public:
    VariableNode* Variable;
    ExpressionNode* Expression;
    StatementAssignmentNode(VariableNode* var,ExpressionNode* expr,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i) override;

    // StatementNode interface
public:
    void ValidateSemantic() override;
};

#endif // STATEMENTASSIGNMENTNODE_H
