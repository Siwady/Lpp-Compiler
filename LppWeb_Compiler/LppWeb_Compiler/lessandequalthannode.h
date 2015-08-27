#ifndef LESSANDEQUALTHANNODE_H
#define LESSANDEQUALTHANNODE_H
#include "expressionnode.h"

class LessAndEqualThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LessAndEqualThanNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // LESSANDEQUALTHANNODE_H
