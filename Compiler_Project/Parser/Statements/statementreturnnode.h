#ifndef STATEMENTRETURNNODE_H
#define STATEMENTRETURNNODE_H
#include "statementnode.h"
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"

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
