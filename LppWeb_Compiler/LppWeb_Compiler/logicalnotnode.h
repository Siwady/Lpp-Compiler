#ifndef LOGICALNOTNODE_H
#define LOGICALNOTNODE_H
#include "expressionnode.h"

class LogicalNotNode : public ExpressionNode
{
public:
    ExpressionNode *Expression;
    LogicalNotNode(ExpressionNode* expression);
};

#endif // LOGICALNOTNODE_H
