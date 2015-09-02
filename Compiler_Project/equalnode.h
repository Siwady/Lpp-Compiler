#ifndef EQUALNODE_H
#define EQUALNODE_H
#include "expressionnode.h"
#include "helper.h"

class EqualNode : public ExpressionNode
{
public:
    ExpressionNode* LeftNode;
    ExpressionNode* RightNode;
    EqualNode(ExpressionNode* left,ExpressionNode* right);

    // ExpressionNode interface
public:
    string ToXML(int i);
};

#endif // EQUALNODE_H
