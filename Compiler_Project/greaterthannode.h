#ifndef GREATERTHANNODE_H
#define GREATERTHANNODE_H
#include "expressionnode.h"

class GreaterThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    GreaterThanNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // GREATERTHANNODE_H
