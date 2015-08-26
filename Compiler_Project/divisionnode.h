#ifndef DIVISIONNODE_H
#define DIVISIONNODE_H
#include "expressionnode.h"

class DivisionNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    DivisionNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // DIVISIONNODE_H
