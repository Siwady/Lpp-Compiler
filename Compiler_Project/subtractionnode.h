#ifndef SUBTRACTIONNODE_H
#define SUBTRACTIONNODE_H
#include "expressionnode.h"

class SubtractionNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    SubtractionNode(ExpressionNode* left,ExpressionNode* right);
};

#endif // SUBTRACTIONNODE_H
