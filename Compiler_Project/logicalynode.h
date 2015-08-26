#ifndef LOGICALYNODE_H
#define LOGICALYNODE_H
#include "expressionnode.h"

class LogicalYNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LogicalYNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // LOGICALYNODE_H
