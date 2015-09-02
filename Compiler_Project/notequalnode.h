#ifndef NOTEQUALNODE_H
#define NOTEQUALNODE_H
#include "expressionnode.h"
#include "helper.h"

class NotEqualNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    NotEqualNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // NOTEQUALNODE_H
