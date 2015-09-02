#ifndef LESSTHANNODE_H
#define LESSTHANNODE_H
#include "expressionnode.h"
#include "helper.h"

class LessThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    LessThanNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // LESSTHANNODE_H
