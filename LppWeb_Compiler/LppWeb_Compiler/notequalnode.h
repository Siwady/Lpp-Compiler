#ifndef NOTEQUALNODE_H
#define NOTEQUALNODE_H
#include "expressionnode.h"

class NotEqualNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    NotEqualNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // NOTEQUALNODE_H
