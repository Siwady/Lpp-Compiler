#ifndef SUMNODE_H
#define SUMNODE_H
#include "expressionnode.h"

class SumNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    SumNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // SUMNODE_H
