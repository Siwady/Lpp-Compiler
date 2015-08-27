#ifndef STATEMENTRETURNNODE_H
#define STATEMENTRETURNNODE_H
#include "statementnode.h"
#include "expressionnode.h"

class StatementReturnNode : public StatementNode
{
public:
    ExpressionNode* Expression;
    StatementReturnNode(ExpressionNode* expr);
};

#endif // STATEMENTRETURNNODE_H
