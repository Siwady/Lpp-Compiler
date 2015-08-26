#ifndef LESSTHANNODE_H
#define LESSTHANNODE_H
#include "expressionnode.h"

class LessThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LessThanNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // LESSTHANNODE_H
