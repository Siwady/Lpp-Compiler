#ifndef STATEMENTRETURNNODE_H
#define STATEMENTRETURNNODE_H
#include "statementnode.h"
#include "../Expressions/expressionnode.h"

class StatementReturnNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    StatementReturnNode(ExpressionNode* expr,int row,int column);

    // StatementNode interface
public:
    string ToXML(int i);

    // StatementNode interface
public:
    void ValidateSemantic();
};

#endif // STATEMENTRETURNNODE_H
