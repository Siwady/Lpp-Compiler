#ifndef MODNODE_H
#define MODNODE_H
#include "expressionnode.h"

class ModNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* Right;
    ModNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // MODNODE_H
