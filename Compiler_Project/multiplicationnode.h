#ifndef MULTIPLICATIONNODE_H
#define MULTIPLICATIONNODE_H
#include "expressionnode.h"

class MultiplicationNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    MultiplicationNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // MULTIPLICATIONNODE_H
