#ifndef GREATERANDEQUALTHANNODE_H
#define GREATERANDEQUALTHANNODE_H
#include "expressionnode.h"

class GreaterAndEqualThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    GreaterAndEqualThanNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // GREATERANDEQUALTHANNODE_H
