#ifndef MODNODE_H
#define MODNODE_H
#include "expressionnode.h"
#include "helper.h"

class ModNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    ModNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // MODNODE_H
