#ifndef INTEGERDIVISIONNODE_H
#define INTEGERDIVISIONNODE_H
#include "expressionnode.h"

class IntegerDivisionNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    IntegerDivisionNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // INTEGERDIVISIONNODE_H
