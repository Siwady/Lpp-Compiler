#ifndef EQUALNODE_H
#define EQUALNODE_H
#include "expressionnode.h"

class EqualNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    EqualNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // EQUALNODE_H
