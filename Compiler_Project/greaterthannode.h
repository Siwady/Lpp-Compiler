#ifndef GREATERTHANNODE_H
#define GREATERTHANNODE_H
#include "expressionnode.h"
#include "helper.h"

class GreaterThanNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    GreaterThanNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // GREATERTHANNODE_H
