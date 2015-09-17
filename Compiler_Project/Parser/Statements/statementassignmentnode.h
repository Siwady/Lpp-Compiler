#ifndef STATEMENTASSIGNMENTNODE_H
#define STATEMENTASSIGNMENTNODE_H
#include "statementnode.h"
#include "Parser/Expressions/Variables/variablenode.h"
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"
#include "Semantic/semanticexception.h"

class StatementAssignmentNode : public StatementNode
{
public:
    VariableNode* Variable;
    ExpressionNode* Expression;
    StatementAssignmentNode(VariableNode* var,ExpressionNode* expr,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTASSIGNMENTNODE_H
