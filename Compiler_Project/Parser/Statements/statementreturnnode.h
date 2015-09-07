#ifndef STATEMENTRETURNNODE_H
#define STATEMENTRETURNNODE_H
#include "statementnode.h"
#include "Parser/Expressions/expressionnode.h"
#include "helper.h"

class StatementReturnNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    StatementReturnNode(ExpressionNode* expr);

    // StatementNode interface
public:
    string ToXML(int i);
};

#endif // STATEMENTRETURNNODE_H
